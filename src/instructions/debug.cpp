/* This file is part of the sirit project.
 * Copyright (c) 2019 sirit
 * This software may be used and distributed according to the terms of the
 * 3-Clause BSD License
 */

#include "sirit/sirit.h"

#include "common_types.h"
#include "stream.h"

namespace Sirit {

Id Module::Name(Id target, std::string_view) {
    return target;
}

Id Module::MemberName(Id type, u32 , std::string_view ) {
    return type;
}

Id Module::String(std::string_view string) {
    debug->Reserve(3 + WordsInString(string));
    return *debug << OpId{spv::Op::OpString} << string << EndOp{};
}

Id Module::OpLine(Id file, Literal line, Literal column) {
    debug->Reserve(4);
    return *debug << spv::Op::OpLine << file << line << column << EndOp{};
}

} // namespace Sirit
