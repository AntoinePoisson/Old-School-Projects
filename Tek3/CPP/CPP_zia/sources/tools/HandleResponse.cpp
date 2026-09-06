/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** HandleResponse
*/

#include <memory>
#include <cstring>
#include <string>
#include <vector>

#include "../Zia.hpp"
#include "HandleResponse.hpp"

template<typename T>
void Zia::HandleResponse::add_some_to_vector(std::vector<char> &dest, const T &src)
{
    int vect_index = dest.size();
    dest.resize(dest.size() + src.size());
    for (char c: src)
        dest[vect_index++] = c;
}

    //! Public
const std::vector<char> Zia::HandleResponse::convertResponse(const Zia::IResponse &res)
{
    std::vector<char> result;

    result.clear();
    if (listCodeStatus.find(res.getCode()) == listCodeStatus.end()) {
        return genRespInterErrServer();
    }

    std::string tmp = "HTTP/1.1 " + std::to_string(res.getCode()) + " " + listCodeStatus.find(res.getCode())->second + "\r\n";
    const std::string *header(res.getHeader(BYPASS_API_LIMITATION));
    const std::vector<char> *body = res.getBody();

    if (header)
        tmp += *header;
    if (body != nullptr && body->size() != 0 && res.getHeader("Content-Length") == nullptr)
        tmp += "Content-Length: " + std::to_string(res.getBody()->size()) + "\r\n";

    tmp += "\r\n";
    add_some_to_vector(result, tmp);
    if (body == nullptr)
        return result;
    if (body != nullptr && body->size() != 0) {
        add_some_to_vector(result, *body);
    }
    return (result);
}

const std::vector<char> Zia::HandleResponse::genRespInterErrServer(void)
{
    std::vector<char> vect_result;
    std::string result;

    result += "HTTP/1.1 500 Internal Server Error\r\n";
    result += "Connection: Closed\r\n";
    result += "Content-Type: text/html; charset=iso-8859-1\r\n";
    result += "Content-Length: 253\r\n";
    result += "\r\n";
    result += "<!DOCTYPE HTML PUBLIC \"-//IETF//DTD HTML 2.0//EN\">";
    result += "<html>";
    result += "<head>";
    result += "<title>500 Internal Server Error</title>";
    result += "</head>";
    result += "<body>";
    result += "<h1>Internal Server Error</h1>";
    result += "<p>Sorry, it's me, not you.</p>";
    result += "<p>&#58;&#40;</p>";
    result += "<p><a href=\"/\">Let me try again!</a></p>";
    result += "</body>";
    result += "</html>";
    add_some_to_vector(vect_result, result);
    return (vect_result);
}

const std::vector<char> Zia::HandleResponse::genRespErr(size_t code)
{
    std::string result;
    std::vector<char> vect_result;
    std::string body;

    if (listCodeStatus.find(code) == listCodeStatus.end()) {
        return genRespInterErrServer();
    }
    body = "<!DOCTYPE HTML PUBLIC><html><head><title>" + std::to_string(code) + " " + (listCodeStatus.at(code)) + " </title></head><body><h1>" + (listCodeStatus.at(code)) + "</h1><p>Ah c est dommage, y a un probleme frerot...</p></body></html>";
    result += "HTTP/1.1 " + std::to_string(code) + " " + (listCodeStatus.at(code)) + "\r\n";
    result += "Connection: Closed\r\n";
    result += "Content-Type: text/html; charset=utf-8\r\n";
    result += "Content-Length: " + std::to_string(body.size()) + "\r\n";
    result += "\r\n";
    result += body;
    add_some_to_vector(vect_result, result);
    return (vect_result);
}

void Zia::HandleResponse::sendReponseToClient(const std::vector<char> &res, Zia::IConnection &client)
{
    const char *tmp = &res.front();

    client.log("\n/=====================================\\\n - Response:\n" + std::string(tmp) + "\n\\=====================================/\n");
    client.write(res.size(), tmp);

}

/*
    result += addHeader(res, "Accept-CH-Lifetime");
    result += addHeader(res, "Accept-CH");
    result += addHeader(res, "Accept-Charset");
    result += addHeader(res, "Accept-Encoding");
    result += addHeader(res, "Accept-Language");
    result += addHeader(res, "Accept-Patch");
    result += addHeader(res, "Accept-Post");
    result += addHeader(res, "Accept-Ranges");
    result += addHeader(res, "Accept");
    result += addHeader(res, "Access-Control-Allow-Credentials");
    result += addHeader(res, "Access-Control-Allow-Headers");
    result += addHeader(res, "Access-Control-Allow-Methods");
    result += addHeader(res, "Access-Control-Allow-Origin");
    result += addHeader(res, "Access-Control-Expose-Headers");
    result += addHeader(res, "Access-Control-Max-Age");
    result += addHeader(res, "Access-Control-Request-Headers");
    result += addHeader(res, "Access-Control-Request-Method");
    result += addHeader(res, "Age");
    result += addHeader(res, "Allow");
    result += addHeader(res, "Alt-Svc");
    result += addHeader(res, "Authorization");
    result += addHeader(res, "Cache-Control");
    result += addHeader(res, "Clear-Site-Data");
    result += addHeader(res, "Connection");
    result += addHeader(res, "Content-Disposition");
    result += addHeader(res, "Content-Encoding");
    result += addHeader(res, "Content-Language");
    result += addHeader(res, "Content-Length");
    result += addHeader(res, "Content-Location");
    result += addHeader(res, "Content-Range");
    result += addHeader(res, "Content-Security-Policy-Report-Only");
    result += addHeader(res, "Content-Security-Policy");
    result += addHeader(res, "Content-Type");
    result += addHeader(res, "Cookie");
    result += addHeader(res, "Cookie2");
    result += addHeader(res, "Cross-Origin-Embedder-Policy");
    result += addHeader(res, "Cross-Origin-Opener-Policy");
    result += addHeader(res, "Cross-Origin-Resource-Policy");
    result += addHeader(res, "Date");
    result += addHeader(res, "Device-Memory");
    result += addHeader(res, "Digest");
    result += addHeader(res, "DNT");
    result += addHeader(res, "DPR");
    result += addHeader(res, "Early-Data");
    result += addHeader(res, "ETag");
    result += addHeader(res, "Expect-CT");
    result += addHeader(res, "Expect");
    result += addHeader(res, "Expires");
    result += addHeader(res, "Feature-Policy");
    result += addHeader(res, "Forwarded");
    result += addHeader(res, "From");
    result += addHeader(res, "Host");
    result += addHeader(res, "If-Match");
    result += addHeader(res, "If-Modified-Since");
    result += addHeader(res, "If-None-Match");
    result += addHeader(res, "If-Range");
    result += addHeader(res, "If-Unmodified-Since");
    result += addHeader(res, "Index");
    result += addHeader(res, "Keep-Alive");
    result += addHeader(res, "Large-Allocation");
    result += addHeader(res, "Last-Modified");
    result += addHeader(res, "Link");
    result += addHeader(res, "Location");
    result += addHeader(res, "NEL");
    result += addHeader(res, "Origin");
    result += addHeader(res, "Pragma");
    result += addHeader(res, "Proxy-Authenticate");
    result += addHeader(res, "Proxy-Authorization");
    result += addHeader(res, "Public-Key-Pins-Report-Only");
    result += addHeader(res, "Public-Key-Pins");
    result += addHeader(res, "Range");
    result += addHeader(res, "Referer");
    result += addHeader(res, "Referrer-Policy");
    result += addHeader(res, "Retry-After");
    result += addHeader(res, "Save-Data");
    result += addHeader(res, "Sec-Fetch-Dest");
    result += addHeader(res, "Sec-Fetch-Mode");
    result += addHeader(res, "Sec-Fetch-Site");
    result += addHeader(res, "Sec-Fetch-User");
    result += addHeader(res, "Sec-WebSocket-Accept");
    result += addHeader(res, "Server-Timing");
    result += addHeader(res, "Server");
    result += addHeader(res, "Set-Cookie");
    result += addHeader(res, "Set-Cookie2");
    result += addHeader(res, "SourceMap");
    result += addHeader(res, "Strict-Transport-Security");
    result += addHeader(res, "TE");
    result += addHeader(res, "Timing-Allow-Origin");
    result += addHeader(res, "Tk");
    result += addHeader(res, "Trailer");
    result += addHeader(res, "Transfer-Encoding");
    result += addHeader(res, "Upgrade-Insecure-Requests");
    result += addHeader(res, "Upgrade");
    result += addHeader(res, "User-Agent");
    result += addHeader(res, "Vary");
    result += addHeader(res, "Via");
    result += addHeader(res, "Want-Digest");
    result += addHeader(res, "Warning");
    result += addHeader(res, "WWW-Authenticate");
    result += addHeader(res, "X-Content-Type-Options");
    result += addHeader(res, "X-DNS-Prefetch-Control");
    result += addHeader(res, "X-Forwarded-For");
    result += addHeader(res, "X-Forwarded-Host");
    result += addHeader(res, "X-Forwarded-Proto");
    result += addHeader(res, "X-Powered-By");
    result += addHeader(res, "X-Frame-Options");
    result += addHeader(res, "X-XSS-Protection");
*/