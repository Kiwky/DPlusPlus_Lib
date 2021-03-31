#include "Utilities.h"
#include "Discord.h"

using namespace std;
using namespace web::json;
using namespace web::http;
using namespace web::http::client;
using namespace utility;

namespace DPlusPlus {
	nJson API_Call(const std::string &url, method api_method, const std::string &json_object) {
		try {
			web::json::value json_v;
			web::http::client::http_client client(U(API_URL));
			std::string httpToken = "Bot " + Discord::token;

			http_request req(api_method);

			req.set_request_uri(web::uri(utility::conversions::to_string_t(url)));
			req.headers().add(U("Authorization"), httpToken.c_str());
			req.headers().add(U("User-Agent"), U("DPlusPlus"));
			req.headers().add(U("Content-Type"), U("application/json"));

			if((api_method != methods::GET) && (api_method != methods::HEAD))
				req.set_body(json_object);

			string_t response_string;
			unsigned short code = 0;

			do {
				pplx::task<http_response> requestTask = client.request(req).then([](http_response response) {
					return response;
				});

				requestTask.wait();
				response_string = requestTask.get().extract_string().get();

				code = requestTask.get().status_code();
				std::cout << code << "\n";
			} while(code == 429);

			nJson s = nJson::parse(response_string.begin(), response_string.end());

			//std::cout << s.dump(4);
			return s;
		}
		catch(std::exception &e) {
			std::cout << e.what();
		}
		return "";
	}
}

