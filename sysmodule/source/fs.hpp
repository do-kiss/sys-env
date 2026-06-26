#pragma once
#include <switch.h>
#include <vector>

namespace fs {

    enum VersionOp {
        OP_EQ = 0,  // =
        OP_GE,      // >=
        OP_LE,      // <=
        OP_GT,      // >
        OP_LT,      // <
    };

    struct ProgramEntry {
        std::string id;
        bool hasVersionCheck;   // 是否设置了固件版本条件
        u8  op;                 // VersionOp 枚举值
        u32 version;            // MAKEHOSVERSION(major, minor, micro)
    };

    void Log(const char *log, ...);
    Result EditContent(std::vector<ProgramEntry> &matchList, std::string &env, std::string &del, u32 currentVer);
    Result ParseConfig(std::vector<ProgramEntry> &entries, bool emuNand);

}
