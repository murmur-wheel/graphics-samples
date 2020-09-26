//
// Created by murmur wheel on 2020/9/19.
//

#ifndef FRAMEWORK_VKUT_INSTANCE_H
#define FRAMEWORK_VKUT_INSTANCE_H

#include <memory>
#include <string>
#include <vector>

#include "vkut_api.h"

namespace framework {
class VkutInstance {
 public:
  struct Options {
    std::vector<std::string> enabled_layers;
    std::vector<std::string> enabled_extensions;
  };

  VkutInstance() = default;
  ~VkutInstance();

  const VkutRegistryApi& registry_api() const { return registry_api_; }
  const VkutInstanceApi& instance_api() const { return instance_api_; }
  const VkInstance& vk_instance() const { return vk_instance_; }

  std::vector<VkPhysicalDevice> enumerate_physical_devices() const;

  static std::shared_ptr<VkutInstance> Create(const Options* options);

 private:
  bool init(const Options* options);

  VkutRegistryApi registry_api_;
  VkutInstanceApi instance_api_;

  //
  VkInstance vk_instance_{VK_NULL_HANDLE};
};

using VkutInstancePtr = std::shared_ptr<VkutInstance>;

}  // namespace framework

#endif  // FRAMEWORK_VKUT_INSTANCE_H
