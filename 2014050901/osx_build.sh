#!/bin/sh

# build c/c++ addon
cd lib
nw-gyp configure --target=0.8.6
nw-gyp build
cp build/Release/*.node .
rm -rf build
cd ..

# download node-webkit
curl http://dl.node-webkit.org/v0.8.6/node-webkit-v0.8.6-osx-ia32.zip -o node-webkit.zip
unzip node-webkit.zip
rm credits.html
rm nwsnapshot
rm node-webkit.zip

# create app bundle
rm -rf demo.app
mv node-webkit.app demo.app
zip -r app.nw package.json index.html style.css img lib/demolib.node
rm lib/demolib.node
mv app.nw demo.app/Contents/Resources
rm demo.app/Contents/Resources/nw.icns
cp sqrt.icns demo.app/Contents/Resources
cp Info.plist demo.app/Contents
mv demo.app/Contents/MacOS/node-webkit demo.app/Contents/MacOS/demo
