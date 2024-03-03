#!/usr/bin/env sh
# original source: https://github.com/uber/RIBs/blob/main/ios/tooling/install-xcode-template.sh

# Configuration
XCODE_TEMPLATE_DIR=$HOME'/Library/Developer/Xcode/Templates/File Templates/Algorithm'
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# Copy Algorithm file templates into the local Algorithm template directory
xcodeTemplate () {
  echo "==> Copying up Algorithm Xcode file templates..."

  if [ -d "$XCODE_TEMPLATE_DIR" ]; then
    rm -R "$XCODE_TEMPLATE_DIR"
  fi
  mkdir -p "$XCODE_TEMPLATE_DIR"

  cp -R $SCRIPT_DIR/*.xctemplate "$XCODE_TEMPLATE_DIR"
}

xcodeTemplate

echo "==> ... success!"
echo "==> Algorithm have been set up. In Xcode, select 'New File...' to use Algorithm templates."
