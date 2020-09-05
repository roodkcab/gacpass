// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

var nativePort = null;

var getKeys = function (obj) {
   var keys = [];
   for (var key in obj) {
      keys.push(key);
   }
   return keys;
}

function onNativeMessage(message) {
  console.log(message);
  chrome.tabs.query({active: true, currentWindow: true}, function (tabs) {
    chrome.tabs.sendMessage(tabs[0].id, message, function(response) {});
  });
}

function onDisconnect() {
  nativePort = null;
}

function getHost(data) {
  var a = document.createElement('a');
  a.href = data;
  return a.hostname;
}  

function postMessage(message) {
  var hostName = "com.unifs.gacpass"
  while (true) {
    try {
      if (!nativePort) {
        nativePort = chrome.runtime.connectNative(hostName);
        nativePort.onMessage.addListener(onNativeMessage);
        nativePort.onDisconnect.addListener(onDisconnect);
        setTimeout(function () {  
          console.log(message);
          nativePort.postMessage(message);
        }, 1000);
      } else {
        console.log(message);
        nativePort.postMessage(message);
      }
      break;
    } catch (e) {
      console.log(e);
    }
  }
}

function connect() {
  chrome.commands.onCommand.addListener(function(command) {
    if (command == "open") {
      chrome.tabs.query({ currentWindow: true, active: true }, function (tabs) {
        message = {"host": getHost(tabs[0].url)};
        postMessage(message);
      });
    }
  });
}

connect();
