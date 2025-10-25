#pragma once

#include "kovhalan/kovhalan.hxx"

namespace kovhalan {
namespace adapters {
class ICommand {
 public:
    virtual ~ICommand()    = default;

    virtual void execute() = 0;
};
} // namespace adapters
} // namespace kovhalan