#!/bin/bash
set -e

# Get the directory where the script is located
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# Change to the script's directory, but only within the script's execution
(
  cd "$SCRIPT_DIR"

  cmake -GNinja -DTARGET_GROUP=test -S . -B build_test
  ninja -C build_test
  
  ctest --verbose --rerun-failed --output-on-failure --test-dir build_test
)