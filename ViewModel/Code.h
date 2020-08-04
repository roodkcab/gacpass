#define GAC_HEADER_USE_NAMESPACE
#include "GacPass.h"
#include <string>
#include "cereal/archives/binary.hpp"

using namespace vl::collections;
using namespace vl::stream;
using namespace vl::regex;
using namespace vl::reflection::description;

struct RawCode
{
	std::string website;
	std::string username;
	std::string password;

	template<class Archive>
	void serialize(Archive& archive)
	{
		archive(CEREAL_NVP(website), CEREAL_NVP(username), CEREAL_NVP(password));
	}
};

typedef struct RawCode RawCode;

class Code : public Object, public virtual gacpass::ICode
{
private:
	WString	website;
	WString	username;
	WString	password;

public:
	Code();
	Code(const WString& _website, const WString& _username, const WString& _password);
	Code(RawCode code);
	WString GetWebsite()override;
	WString GetUsername()override;
	WString GetPassword()override;
	void Update(Ptr<gacpass::ICodeBookViewModel> _viewmodel, const WString& _website, const WString& _username, const WString& _password);
  };
