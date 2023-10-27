#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace OThirteen 
{
	class OTHIRTEEN_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Define macros for core log
#define OT_CORE_TRACE(...)      ::OThirteen::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define OT_CORE_INFO(...)       ::OThirteen::Log::GetCoreLogger()->info(__VA_ARGS__)
#define OT_CORE_WARN(...)       ::OThirteen::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define OT_CORE_ERROR(...)      ::OThirteen::Log::GetCoreLogger()->error(__VA_ARGS__)
#define OT_CORE_FATAL(...)      ::OThirteen::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Define macros for client log
#define OT_CLIENT_TRACE(...)    ::OThirteen::Log::GetClientLogger()->trace(__VA_ARGS__)
#define OT_CLIENT_INFO(...)     ::OThirteen::Log::GetClientLogger()->info(__VA_ARGS__)
#define OT_CLIENT_WARN(...)     ::OThirteen::Log::GetClientLogger()->warn(__VA_ARGS__)
#define OT_CLIENT_ERROR(...)    ::OThirteen::Log::GetClientLogger()->error(__VA_ARGS__)
#define OT_CLIENT_FATAL(...)    ::OThirteen::Log::GetClientLogger()->fatal(__VAR_ARGS__)
