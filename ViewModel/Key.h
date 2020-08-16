#pragma once
#define GAC_HEADER_USE_NAMESPACE
#include "GacPass.h"
#include <string>

using namespace vl;

class Key : public Object, public virtual gacpass::IKey
{
private:
	int id;
	WString	key;

public:
	Key();
	Key(const int _id, const WString& _key);
	Key(const Key& key);
	vint GetId()const override;
	void SetId(const vint _id)override;
	WString GetKey()const override;
	void SetKey(const WString& _website)override;
	void Update(const vint _id, const WString& _key)override;
  };