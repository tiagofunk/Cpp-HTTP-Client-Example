/*
 *    Copyright (c) <2002-2005> <Jean-Philippe Barrette-LaPierre>
 *    
 *    Permission is hereby granted, free of charge, to any person obtaining
 *    a copy of this software and associated documentation files 
 *    (curlpp), to deal in the Software without restriction, 
 *    including without limitation the rights to use, copy, modify, merge,
 *    publish, distribute, sublicense, and/or sell copies of the Software,
 *    and to permit persons to whom the Software is furnished to do so, 
 *    subject to the following conditions:
 *    
 *    The above copyright notice and this permission notice shall be included
 *    in all copies or substantial portions of the Software.
 *    
 *    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 *    OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
 *    IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY 
 *    CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
 *    TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 *    SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/**
* file
* Simple POST demo.
* 
*/

// sudo apt-get install libcurl4-openssl-dev
// sudo apt-get install libcurlpp-dev

// g++ test.cpp -o test -lcurl -lcurlpp

#include <cstdlib>
#include <cerrno>
#include "string"

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Exception.hpp>

using std::string;

string url = "http://localhost:3000";
string json = "{\"loglevel\": 1,\"message\": \"example\", \"time\": \"04/08/2021 12:00:00\"}";

void send_post(){
    try {
        curlpp::Cleanup cleaner;
        curlpp::Easy request;
        
        request.setOpt(new curlpp::options::Url(url)); 
        request.setOpt(new curlpp::options::Verbose(true)); 
        
        std::list<std::string> header; 
        header.push_back("Content-Type: application/json"); 
        
        request.setOpt(new curlpp::options::HttpHeader(header)); 
        
        request.setOpt(new curlpp::options::PostFields( json.c_str() ) );
        request.setOpt(new curlpp::options::PostFieldSize( json.size() ) );

        request.setOpt(new curlpp::options::UserPwd("user:password"));
        
        request.perform(); 
    } catch ( curlpp::LogicError & e ) {
        std::cout << e.what() << std::endl;
    } catch ( curlpp::RuntimeError & e ) {
        std::cout << e.what() << std::endl;
    }
}


int main(int argc, char *argv[]){
    for (int i = 0; i < 10; i++ ){
        send_post();
    }
    return EXIT_SUCCESS;
}