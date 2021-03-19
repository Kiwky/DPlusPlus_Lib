#include "Utilities.h"
#include "Discord.h"

using namespace std;
using namespace web::json;
using namespace web::http;
using namespace web::http::client;
using namespace utility;

namespace DPlusPlus {
	nJson API_Call(const std::string &url, method api_method, const std::string &jsonObject) {
		std::cout << "\n\n " << jsonObject << "\n\n";
		try {
			web::json::value json_v;
			web::http::client::http_client client(U(API_URL));
			std::string httpToken = "Bot " + Discord::token;

			http_request req(api_method);

			req.set_request_uri(web::uri(utility::conversions::to_string_t(url)));
			req.headers().add(L"Authorization", httpToken.c_str());
			req.headers().add(L"User-Agent", L"DPlusPlus");
			req.headers().add(L"Content-Type", L"application/json");

			if((api_method != methods::GET) && (api_method != methods::HEAD))
				req.set_body(jsonObject);

			pplx::task<http_response> requestTask = client.request(req).then([](http_response response) {
				return response;
			});

			requestTask.wait();
			auto response_string = requestTask.get().extract_string().get();
			std::cout << response_string.c_str() << std::endl;

			nJson s = nJson::parse(response_string.begin(), response_string.end());
			std::cout << s << "\n";
			return s;
		}
		catch(std::exception &e) {
			std::cout << e.what();
		}

	}
}