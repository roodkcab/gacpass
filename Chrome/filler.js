chrome.runtime.onMessage.addListener(function (request, sender, sendResponse) {
  $(":password").val(request.text);
  return true;
});
