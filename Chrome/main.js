// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

function getHost(data) {
  var    a      = document.createElement('a');
         a.href = data;
  return a.hostname;
}

function appendMessage(text) {
  document.getElementById('response').innerHTML += "<p>" + text + "</p>";
}

document.addEventListener('DOMContentLoaded', function () {
  var gacpassPort = chrome.runtime.connect({name: "gacpass"});

  gacpassPort.onMessage.addListener(function(response) {
    console.log(response);
    chrome.tabs.query({active: true, currentWindow: true}, function(tabs){
      chrome.tabs.sendMessage(tabs[0].id, response, function(response) {});
    });
  });

  chrome.tabs.query({ currentWindow: true, active: true }, function (tabs) {
    message = {"host": getHost(tabs[0].url)};
    gacpassPort.postMessage(message);
  });
});
