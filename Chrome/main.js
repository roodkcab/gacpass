// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

var port = null;

var getKeys = function(obj){
   var keys = [];
   for(var key in obj){
      keys.push(key);
   }
   return keys;
}


function appendMessage(text) {
  document.getElementById('response').innerHTML += "<p>" + text + "</p>";
}

/*function updateUiState() {
  if (port) {
    document.getElementById('connect-button').style.display = 'none';
    document.getElementById('input-text').style.display = 'block';
    document.getElementById('send-message-button').style.display = 'block';
  } else {
    document.getElementById('connect-button').style.display = 'block';
    document.getElementById('input-text').style.display = 'none';
    document.getElementById('send-message-button').style.display = 'none';
  }
}*/

function onNativeMessage(message) {
  appendMessage("Received message: <b>" + JSON.stringify(message) + "</b>");
}

function onDisconnect() {
  appendMessage("Failed to connect: " + chrome.runtime.lastError.message);
  port = null;
}

function connect() {
  var hostName = "com.unifs.gacpass"
  appendMessage("Connecting to native messaging host <b>" + hostName + "</b>")
  port = chrome.runtime.connectNative(hostName);
  port.onMessage.addListener(onNativeMessage);
  port.onDisconnect.addListener(onDisconnect);

  //check GacPass is ready
  chrome.tabs.query({ currentWindow: true, active: true }, function (tabs) {
    message = {"host": getHost(tabs[0].url)};
    setTimeout(function(){  
      port.postMessage(message);
      appendMessage("Sent message: <b>" + JSON.stringify(message) + "</b>");
    }, 1000);
  });
}


function getHost(data) {
  var    a      = document.createElement('a');
         a.href = data;
  return a.hostname;
}

document.addEventListener('DOMContentLoaded', function () {
  connect();
});
