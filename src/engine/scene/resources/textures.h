#pragma once

// Сторонние библиотеки
#include <stb_image.h>

// Внутренние библиотеки
#include "core.h"

// Стандартные библиотеки
#include <list>
#include <string>
#include <vector>
#include <utility>
#include <unordered_map>

class Textures {
 public:
  typedef Textures* Manager;
  typedef struct texture_t {
    int width, height;
    VkImage image;
    VkImageView view;
    VkDeviceSize size;
    VkDeviceMemory memory;
  } * Instance;

 private:
  Core::Manager core;

  std::vector<Instance> handlers;
  std::unordered_map<std::string, uint32_t> idList;

 public:
  explicit Textures(Core::Manager);
  ~Textures();

  Instance load(const std::string& name);
  void destroy(const std::string& name);

  Instance get(const std::string& name);
  uint32_t getID(const std::string& name);
  void getViews(std::vector<VkImageView>&);

 private:
  Instance create(const std::string& name);
};
