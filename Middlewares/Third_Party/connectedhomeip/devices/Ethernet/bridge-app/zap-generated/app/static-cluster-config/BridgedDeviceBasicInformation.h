// DO NOT EDIT - Generated file
//
// Application configuration for BridgedDeviceBasicInformation based on EMBER configuration
// from C:/chip-matter-tools/ZAP_Generation_v2025.10.23/devices/Ethernet/bridge-app/zap-generated/zap/bridge-app.matter
#pragma once

#include <app/util/cluster-config.h>
#include <clusters/BridgedDeviceBasicInformation/AttributeIds.h>
#include <clusters/BridgedDeviceBasicInformation/CommandIds.h>
#include <clusters/BridgedDeviceBasicInformation/Enums.h>

#include <array>

namespace chip {
namespace app {
namespace Clusters {
namespace BridgedDeviceBasicInformation {
namespace StaticApplicationConfig {
namespace detail {
inline constexpr AttributeId kEndpoint2EnabledAttributes[] = {
    Attributes::AcceptedCommandList::Id,
    Attributes::AttributeList::Id,
    Attributes::ClusterRevision::Id,
    Attributes::FeatureMap::Id,
    Attributes::GeneratedCommandList::Id,
    Attributes::NodeLabel::Id,
    Attributes::Reachable::Id,
    Attributes::UniqueID::Id,
};
} // namespace detail

using FeatureBitmapType = Feature;

inline constexpr std::array<Clusters::StaticApplicationConfig::ClusterConfiguration<FeatureBitmapType>, 1> kFixedClusterConfig = { {
    {
        .endpointNumber    = 2,
        .featureMap        = BitFlags<FeatureBitmapType>{},
        .enabledAttributes = Span<const AttributeId>(detail::kEndpoint2EnabledAttributes),
        .enabledCommands   = Span<const CommandId>(),
    },
} };

// If a specific attribute is supported at all across all endpoint static instantiations
inline constexpr bool IsAttributeEnabledOnSomeEndpoint(AttributeId attributeId)
{
    switch (attributeId)
    {
    case Attributes::AcceptedCommandList::Id:
    case Attributes::AttributeList::Id:
    case Attributes::ClusterRevision::Id:
    case Attributes::FeatureMap::Id:
    case Attributes::GeneratedCommandList::Id:
    case Attributes::NodeLabel::Id:
    case Attributes::Reachable::Id:
    case Attributes::UniqueID::Id:
        return true;
    default:
        return false;
    }
}

// If a specific command is supported at all across all endpoint static instantiations
inline constexpr bool IsCommandEnabledOnSomeEndpoint(CommandId commandId)
{
    switch (commandId)
    {
    default:
        return false;
    }
}

} // namespace StaticApplicationConfig
} // namespace BridgedDeviceBasicInformation
} // namespace Clusters
} // namespace app
} // namespace chip
