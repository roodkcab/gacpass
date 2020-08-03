#include "Code.h"
#include "CodeBookViewModel.h"

Ptr<IValueObservableList> CodeBookViewModel::GetCodes()
{
	return codes.GetWrapper();
}
Ptr<gacpass::ICode> CodeBookViewModel::GetSelectedCode()
{
	return selectedCode;
}

void CodeBookViewModel::SetSelectedCode(Ptr<gacpass::ICode> value)
{
	if (selectedCode != value)
	{
		selectedCode = value;
		SelectedCodeChanged();
	}
}

Ptr<gacpass::ICode> CodeBookViewModel::CreateCode()
{
	return new Code();
}

void CodeBookViewModel::AddCode(Ptr<gacpass::ICode> code)
{
	codes.Add(code);
}

void CodeBookViewModel::NotifyUpdate(gacpass::ICode* code)
{
	vint index = codes.IndexOf(code);
	if (index != -1)
	{
		codes.NotifyUpdate(index, 1);
	}
}
