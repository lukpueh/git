#ifndef TAG_H
#define TAG_H

#include "object.h"

extern const char *tag_type;

struct tag {
	struct object object;
	struct object *tagged;
	char *tag;
	unsigned long date;
};

extern struct tag *lookup_tag(const unsigned char *sha1);
extern int parse_tag_buffer(struct tag *item, const void *data, unsigned long size);
extern int parse_tag(struct tag *item);
extern struct object *deref_tag(struct object *, const char *, int);
extern struct object *deref_tag_noverify(struct object *);
extern int verify_and_format_tag(const unsigned char *sha1,
		const char *name_to_report, const char *fmt_pretty, unsigned flags);

#endif /* TAG_H */
