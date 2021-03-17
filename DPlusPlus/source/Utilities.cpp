#include "Utilities.h"

namespace DPlusPlus {
	void API_Call(const std::string &url, method api_method, const std::string &jsonObject) {
		try {
			web::json::value json_v;
			web::http::client::http_client client(U(API_URL));

			http_request req(api_method);

			req.set_request_uri(web::uri(utility::conversions::to_string_t(url)));
			req.headers().add(L"Authorization", L"Bot Nzk1NzU1ODUxOTgxMzg5ODY0.X_N_Yw.FVZc3RA0USFtjjogGzvRTbhGwO4");
			req.headers().add(L"User-Agent", L"DPlusPlus");
			req.headers().add(L"Content-Type", L"application/json");

			req.set_body(jsonObject);
			client.request(req);
		}
		catch(std::exception &e) {
			std::cout << e.what();
		}
	}
}