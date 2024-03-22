#include "rss20parser.h"

#include <cstring>

#include "config.h"
#include "feed.h"
#include "item.h"
#include "rss09xparser.h"
#include "utils.h"

#define RSS20USERLAND_URI "http://backend.userland.com/rss2"

using namespace newsboat;

namespace rsspp {

void Rss20Parser::parse_feed(Feed& f, xmlNode* rootNode)
{
	if (rootNode->ns) {
		const char* ns = (const char*)rootNode->ns->href;
		if (strcmp(ns, RSS20USERLAND_URI) == 0) {
			this->ns = strdup(ns);
		}
	}

	Rss09xParser::parse_feed(f, rootNode);
}

} // namespace rsspp
