#!/bin/bash

unameOut="$(uname -s)"
case "${unameOut}" in
  Linux*)   MACHINE=linux;;
  Darwin*)	MACHINE=macos;;
	CYGWIN*)	MACHINE=cygwin;;
	MINGW*)		MACHINE=mingw;;
	*)		MACHINE="UNKNOWN:${unameOut}"
esac

MACHINE=$(echo "${MACHINE}" | awk '{print tolower($0)}')

if [ "$MACHINE" == "mingw" ]; then
	SCRIPTDIR=Scripts
	PYTHON=python
else
	SCRIPTDIR=bin
	PYTHON=$(which python3)
fi

MYVENV="venv"
# Activate the new environment
echo "Activating the virtual environment..."
source "${MYVENV}/${SCRIPTDIR}/activate"

mkdir -p build/python_bindings/Debug
mkdir -p build/python_bindings/Release
cd build/python_bindings

if [[ -z "${NPROC}" ]]; then (( NPROC = $(nproc) - 1 )); fi

if [ "${MACHINE}" == "macos" ]; then
  cd Debug
  cmake ../../../python_bindings_standalone -DCMAKE_BUILD_TYPE="Debug"
  cd ../Release
  cmake ../../../python_bindings_standalone -DCMAKE_BUILD_TYPE="Release"
elif [ "${MACHINE}" == "linux" ]; then
  cd Debug
  cmake ../../../python_bindings_standalone -DCMAKE_BUILD_TYPE="Debug"
  cd ../Release
  cmake ../../../python_bindings_standalone -DCMAKE_BUILD_TYPE="Release"
else
  WINARCH="x64"
  if [[ $PROCESSOR_IDENTIFIER == *"ARM"* ]]; then WINARCH="ARM64"; fi
  cd Debug
  cmake -A "${WINARCH}" ../../../python_bindings_standalone -DCMAKE_BUILD_TYPE="Debug"
  cd ../Release
  cmake -A "${WINARCH}" ../../../python_bindings_standalone -DCMAKE_BUILD_TYPE="Release"
fi

if [ "${MACHINE}" == "cygwin" ] || [ "${MACHINE}" == "mingw" ]; then
  cd ../Debug
  CMAKE_BUILD_PARALLEL_LEVEL=3 cmake --build ./ --config "Debug"
  cd ../Release
  CMAKE_BUILD_PARALLEL_LEVEL=3 cmake --build ./ --config "Release"
else
  cd ../Debug
  cmake --build ./ --config "Debug" -j "${NPROC}"
  cd ../Release
  cmake --build ./ --config "Release" -j "${NPROC}"
fi

cd ../../..
