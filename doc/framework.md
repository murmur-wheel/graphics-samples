# framework

框架设计文档

## vkut

vkut 封装了 vulkan api 让其更加容易被使用。

- 加载 vulkan api，不需要使用 Vulkan SDK
- 通过引用计数来管理资源
- 直接从 shader 创建 pipeline layout 和 descriptor layout
- frame graph 支持

## ui

实现参考：https://developer.android.com/guide/topics/ui/how-android-draws

## asset

资源管理

```cpp
auto image = AssetManager::Get()->acquire<Image>("image.png");
AssetManager::Get()->release(image);
```

## input

## platform

平台抽象

## math

数学库
