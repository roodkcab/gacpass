#include "Reference.h"

Reference::Reference()
	: id(-1)
	, codeId(-1)
	, type(gacpass::HostType::Website)
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

::vl::vint Reference::GetId()const
{
	return id;
}

void Reference::SetId(const ::vl::vint _id)
{
	id = _id;
}

::vl::vint Reference::GetCodeId()const
{
	return codeId;
}

void Reference::SetCodeId(const ::vl::vint _codeId)
{
	codeId = _codeId;
}

gacpass::HostType Reference::GetType()const
{
	return type;
}

void Reference::SetType(const gacpass::HostType _type)
{
	type = _type;
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
	id = reference->GetId();
	codeId = reference->GetCodeId();
	type = reference->GetType();
	content = reference->GetContent();
}
