## Goals
* Get a stable working minimal example bot with minimal spaghetti (mostly working, still too much spaghet)
* Get 100% coverage of all API functions (websocket gateway, REST, voice websocket, voice UDP, v1.0 release)
* ~~Discord developer ToS compliant~~ compliance will be up to bot developers, although the library will try to include 
some convenience functions to make this easier if nessecary
* ~~A bot that can turn your lights on~~ too vague

## Todo
Ordered roughly in terms of priority.

### Library
* see if we want to use libuv for libdiscord - libwebsockets and libcurl
  * figure out how libuv 
* Basic metadata manipulation functions: sublibrary/module for JSON data payloads/structs for lower level abstraction
* Better documentation (comments in the source code is NOT good documentation)
* helper function to verify if a bot token is valid without connecting to discord

### Websocket
* look into potentially migrating to LWS 3.0
* More callbacks
* Sharding
* merge ld_connect and ld_service

### REST
* Nonblocking HTTP requests
* Ratelimiting
* Try using OpenSSL to see if our "unexpected TLS packet" error goes away
* Add way of logging bot actions through a Discord channels (use Discord channel for logging)

### JSON
* JSON manipulation/creation functions for each type of JSON object that the API will send to us
* Consider changing the snowflake type to uint64_t
* string to snowflake function
* Timestamp manipulation functions
    * Make/find functions that will encode/decode ISO8601-formatted strings. Will GNU save us?
    
### Example Bots
#### minimal - Minimal example websocket bot
* get it working

#### ayylmao - A Basic Call and Response Bot
* Bug: space in response CLI option causes spam of the response
* Add support for multiple calls/responses per bot
  * wew-lad?
  * rename bot to call-response when this is implemented
* Ignore calls from other bots

#### Stalkerbot - Track user presence
* a bot to tell you when your bot crashes (wait...)

#### ping - A Comprehensive Latency Tool
* Measure latency between libcurl and ulfius

#### A Discord CLI Tool
* Shell scripting integration?

#### A Configurable Bot for the Masses
* Look into YAML formatting
* YAML -> JSON converter? Support multiple config types

## Planned
* Git submodules to statically link some dependencies (cygwin)
* zlib compression support in gateway payloads (check other compression methods in gateway connections)
* See if jansson increment/decrement needs to be used
* More elaborate CMake setup for OS detection, dependency checks

## Far Future
* Rich presence integration?
* OAuth2 support (write/find a OAuth2 client library for C)
* Support for voice channels (UDP connections, use libuv?)
* Support for file-based bot configuration allowing in-flight changing of bot behavior
* Example bot with image generation integration (Allegro 5 bitmaps? MagickWand? SDL?)
* Support for userbots
* A Discord CLI client (not necessarily as an example app - may be a separate app)
* Test on a ESP32
* Support for MinGW, Cygwin, or WSL
* Spotify rich presence integration
* Make/autogenerate wrapper for other languages, including Python, C++, Rust, and Go.

## Far Far Future
* Discord as a Filesystem (DaaFS)