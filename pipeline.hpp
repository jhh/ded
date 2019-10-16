#pragma once
#include "config/pipeline_config.hpp"
#include "config/stream_config.hpp"
#include "pipeline/pipeline.hpp"

namespace ded {
class NullPipeline : public deadeye::Pipeline {
 public:
  NullPipeline(int inum) : deadeye::Pipeline{inum} {}
  void CancelTask() override {}
  void UpdateConfig(deadeye::PipelineConfig *) override {}
  void UpdateStream(deadeye::StreamConfig *) override {}
  void Run() override { spdlog::warn("{}: Run not implemented", *this); }

 protected:
  virtual std::string ToString() const override {
    return "ded::NullPipeline<" + std::to_string(inum_) + ">";
  }
};

}  // namespace ded
