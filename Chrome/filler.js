chrome.runtime.onMessage.addListener(function (request, sender, sendResponse) {
  let password = $(":password");
  password.val(request.password);

  let idx = $("input").toArray().indexOf(password[0]);
  let username = $($("input")[idx - 1]);
  username.val(request.username);
  return true;
});
