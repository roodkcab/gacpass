#pragma once
#define GAC_HEADER_USE_NAMESPACE
#include "Gacpass.h"
#include <string>

using namespace vl;

class Reference : public Object, public virtual gacpass::IReference
{
private:
	int id;
	int codeId;
	gacpass::HostType type;
	WString	content;

public:
	Reference();
	Reference(const Reference& reference);
	//Reference(const int _id, const int _codeId, const int _type, const WString& _content);
	int GetId()const override;
	void SetId(const int _id)override;
	int GetCodeId()const override;
	void SetCodeId(const int _codeId)override;
	gacpass::HostType GetType()const override;
	void SetType(const gacpass::HostType _type)override;
	WString GetContent()const override;
	void SetContent(const WString& _content)override;
	void Update(Ptr<IReference> reference)override;
};

