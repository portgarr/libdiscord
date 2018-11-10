//
// Created by dxing97 on 1/15/18.
//


#ifndef LIBDISCORD_REST_H
#define LIBDISCORD_REST_H

#include <curl/curl.h>
//#include <ulfius.h>
#include <libdiscord.h>

struct ld_context; //anonymous declaration

/*
 * functions related to the REST API
 *
 */

/*
 * HTTP verb enums.
 */
enum ld_rest_http_verb {
    LD_REST_VERB_GET,
    LD_REST_VERB_PUT,
    LD_REST_VERB_POST,
    LD_REST_VERB_PATCH,
    LD_REST_VERB_DELETE
};

/*
 * rather opaque structure used to process headers into libcurl
 */
struct ld_headers {
//    struct _u_map *umap;
    int length;
    char **key;
    char **value;
};

/*
 * http request fields
 */
struct ld_rest_request {
    enum ld_rest_http_verb verb;
    char *base_url;
    char *endpoint;
    char *body;
    size_t body_size;
    struct ld_headers *headers;
    int timeout; //ulfius default is 0
    char *user_agent;
};



struct ld_rest_response {
    long http_status;
    struct _u_map *headers;
    void *body;
    size_t body_length;
};

//put header key/value pair into
int ld_headers_put(struct ld_headers *headers, char *key, char *value);

//removes everything from the header
int ld_headers_clean(struct ld_headers *headers);

//remove a specific header matching to this key
int ld_headers_remove

/*
 * allocates memory
 * initializes a request with defaults
 */
struct ld_rest_request *ld_rest_init_request(struct ld_rest_request *request);

/*
 * allocates memory
 * initializes a response with defaults
 */
struct ld_rest_response * ld_rest_init_response();

/*
 * frees memory for request
 */
int ld_rest_free_request(struct ld_rest_request *request);

/*
 * frees memory for response
 */
int ld_rest_free_response(struct ld_rest_response *response);


/*
 * takes a request, performs it, then saves the response
 * returns 0 on successful request (even if the response is 4XX)
 * rather slow, since it creates and destroys a curl handle.
 * basically a wrapper around ulfius
 */
int ld_rest_send_blocking_request(struct ld_rest_request *request, struct ld_rest_response *response);

/*
 * makes a HTTP request of some kind to some URL with some headers
 * blocking
 */
int _ld_rest_blocking_request(
        enum ld_rest_http_verb verb,
        char *url,
        struct curl_slist headers,
        char *user_agent
);

/*
 * takes a verb enum and returns a read-only string for that verb. DO NOT MODIFY THE RETURNED VALUE, it is read-only
 */
char *ld_rest_verb_enum2str(enum ld_rest_http_verb verb);

/*
 * generates ld_rest_request for GET /gateway
 * does NOT perform the request
 */
struct ld_rest_request *ld_get_gateway(struct ld_rest_request *req, struct ld_context *context);

/*
 * generates ld_rest_request for GET /gateway/bot
 */
struct ld_rest_request *ld_get_gateway_bot(struct ld_rest_request *req, struct ld_context *context);

/*
 * generates a POST request to create a message
 * only supports basic messages (no embeds)
 */
int ld_create_message(struct ld_rest_request *req, struct ld_context *context, const char *channel_id, const char *message_content);

#endif //LIBDISCORD_REST_H
