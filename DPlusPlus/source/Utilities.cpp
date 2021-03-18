#include "Utilities.h"
#include "Discord.h"

using namespace std;
using namespace web::json;
using namespace web::http;
using namespace web::http::client;
using namespace utility;

namespace DPlusPlus {
	void API_Call(const std::string &url, method api_method, const std::string &jsonObject) {
		try {
			web::json::value json_v;
			web::http::client::http_client client(U(API_URL));
			std::string httpToken = "Bot " + Discord::token;

			http_request req(api_method);

			req.set_request_uri(web::uri(utility::conversions::to_string_t(url)));
			req.headers().add(L"Authorization", httpToken.c_str());
			req.headers().add(L"User-Agent", L"DPlusPlus");
			req.headers().add(L"Content-Type", L"application/json");

			//req.set_body(jsonObject);
			//client.request(req);

			web::json::value ret;
			pplx::task<http_response> requestTask = client.request(req).then([](http_response response) {
				return response;
			});

			requestTask.wait();
			ret = value::parse(requestTask.get().extract_string().get());

			std::wcout << ret;
		}
		catch(std::exception &e) {
			std::cout << e.what();
		}
	}
}