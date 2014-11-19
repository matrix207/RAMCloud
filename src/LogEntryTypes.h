/* Copyright (c) 2009-2012 Stanford University
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR(S) DISCLAIM ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL AUTHORS BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef RAMCLOUD_LOGENTRYTYPES_H
#define RAMCLOUD_LOGENTRYTYPES_H

namespace RAMCloud {

/**
 * Each entry in the log has an 8-bit type field that identifies it.
 *
 * When adding entries, also update the LogEntryTypeHelpers::toString()
 * method below.
 */
enum LogEntryType {
    /// Invalid log entry. This type should never be used.
    LOG_ENTRY_TYPE_INVALID = 0,

    /// See LogMetadata.h::SegmentHeader
    LOG_ENTRY_TYPE_SEGHEADER,

    /// See Object.h::Object
    LOG_ENTRY_TYPE_OBJ,

    /// See Object.h::ObjectTombstone
    LOG_ENTRY_TYPE_OBJTOMB,

    /// See LogDigest
    LOG_ENTRY_TYPE_LOGDIGEST,

    /// See Object.h::ObjectSafeVersion
    LOG_ENTRY_TYPE_SAFEVERSION,

    /// See TableStats.h::Digest
    LOG_ENTRY_TYPE_TABLESTATS,

    /// See Object.h::RpcRecord
    LOG_ENTRY_TYPE_RPCRECORD,

    /// Not a type, but rather the total number of types we have defined.
    /// This is currently restricted by the lower 6 bits in a uint8_t field
    /// in Segment.h's Segment::EntryHeader. RAMCloud will probably collapse
    /// under it's own complexity before we exceed 64 types.
    TOTAL_LOG_ENTRY_TYPES
};

namespace LogEntryTypeHelpers {

const char* toString(LogEntryType type);

} // namespace LogEntryTypeHelpers

} // namespace RAMCloud

#endif // !RAMCLOUD_LOGENTRYTYPES_H
