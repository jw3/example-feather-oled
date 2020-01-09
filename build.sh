#!/usr/bin/env bash

if [ -z "$1" ]; then echo "usage: $0 <platform>"; exit 1; fi

readonly platform="$1"
cmake_args=("-DPLATFORM=$platform")

readonly builddir="build-$platform"

readonly cross_compiler_root=${CROSS_COMPILER_ROOT:-/usr/local/gcc-arm}
readonly compiler_major_version=$("${cross_compiler_root}/bin/arm-none-eabi-gcc" -dumpspecs | grep *version -A1 | tail -n1 | cut -d. -f1)

if [[ "$2" != "quick" ]]; then
  rm -rf "$builddir"
  mkdir "$builddir"
fi

if [ ! -d "$builddir" ]; then mkdir "$builddir"; fi

build() {
  conan install . -if="$builddir" -s compiler.version="$compiler_major_version"
  cd "$builddir"
  cmake .. ${cmake_args[@]}
  make -j1
}

package() {
  readonly conanpath="${CONAN_PATH:-${sourcedir}}"
  readonly conanuser="${CONAN_USER:-jw3}"
  readonly conanchannel="${CONAN_CHANNEL:-stable}"

  export FW_SRC_DIR="."
  conan export-pkg . "$conanuser/$conanchannel" -s compiler.version="$compiler_major_version" -sf src -f
}

build "$@"
