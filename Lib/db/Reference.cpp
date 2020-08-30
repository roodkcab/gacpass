#include "Reference.h"

Reference::Reference()
	: id(-1)
	, codeId(-1)
	, type(1)
	, content(L"")
{
}

/*Reference::Reference(const int _id, const int _codeId, const int _type, const WString& _content)
{
	id = _id;
	codeId = _codeId;
	type = _type;
	content = _content;
}*/

Reference::Reference(const Reference& reference)
{
	id = reference.id;
	codeId = reference.codeId;
	type = reference.type;
	content = reference.content;
}

int Reference::GetId()const
{
	return id;
}

void Reference::SetId(const int _id)
{
	id = _id;
}

int Reference::GetCodeId()const
{
	return codeId;
}

void Reference::SetCodeId(const int _codeId)
{
	codeId = _codeId;
}

WString Reference::GetContent()const
{
	return content;
}

void Reference::SetContent(const WString& _content)
{
	content = _content;
}

void Reference::Update(Ptr<IReference> reference)
{
}
