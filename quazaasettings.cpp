//
// quazaasettings.cpp
//
// Copyright � Quazaa Development Team, 2009-2010.
// This file is part of QUAZAA (quazaa.sourceforge.net)
//
// Quazaa is free software; you can redistribute it
// and/or modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2 of
// the License, or (at your option) any later version.
//
// Quazaa is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Quazaa; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

#include "quazaasettings.h"
#include "quazaaglobals.h"
#include <QSettings>
#include <QUuid>
#include <QDesktopServices>

QuazaaSettings quazaaSettings;

QuazaaSettings::QuazaaSettings()
{
}

void QuazaaSettings::saveSettings()
{
	QSettings m_qSettings(quazaaGlobals.ApplicationOrganizationName(), quazaaGlobals.ApplicationName());

	m_qSettings.beginGroup("Live");
	m_qSettings.setValue("AdultWarning", quazaaSettings.Live.AdultWarning);
	m_qSettings.setValue("AutoClose", quazaaSettings.Live.AutoClose);
	m_qSettings.setValue("BandwidthScale", quazaaSettings.Live.BandwidthScale);
	m_qSettings.setValue("DefaultED2KServersLoaded", quazaaSettings.Live.DefaultED2KServersLoaded);
	m_qSettings.setValue("DiskSpaceStop", quazaaSettings.Live.DiskSpaceStop);
	m_qSettings.setValue("DiskSpaceWarning", quazaaSettings.Live.DiskSpaceWarning);
	m_qSettings.setValue("DiskWriteWarning", quazaaSettings.Live.DiskWriteWarning);
	m_qSettings.setValue("DonkeyServerWarning", quazaaSettings.Live.DonkeyServerWarning);
	m_qSettings.setValue("LastDuplicateHash", quazaaSettings.Live.LastDuplicateHash);
	m_qSettings.setValue("MaliciousWarning", quazaaSettings.Live.MaliciousWarning);
	m_qSettings.setValue("QueueLimitWarning", quazaaSettings.Live.QueueLimitWarning);
	m_qSettings.setValue("UploadLimitWarning", quazaaSettings.Live.UploadLimitWarning);
	m_qSettings.endGroup();

	m_qSettings.beginGroup("Basic");
	m_qSettings.setValue("ChatTips", quazaaSettings.Basic.ChatTips);
	m_qSettings.setValue("CloseMode", quazaaSettings.Basic.CloseMode);
	m_qSettings.setValue("ConnectOnStartup", quazaaSettings.Basic.ConnectOnStartup);
	m_qSettings.setValue("DiskSpaceStop", quazaaSettings.Basic.DiskSpaceStop);
	m_qSettings.setValue("DiskSpaceWarning", quazaaSettings.Basic.DiskSpaceWarning);
	m_qSettings.setValue("DownloadsTips", quazaaSettings.Basic.DownloadsTips);
	m_qSettings.setValue("LibraryTips", quazaaSettings.Basic.LibraryTips);
	m_qSettings.setValue("MediaTips", quazaaSettings.Basic.MediaTips);
	m_qSettings.setValue("MinimizeToTray", quazaaSettings.Basic.MinimizeToTray);
	m_qSettings.setValue("NeighboursTips", quazaaSettings.Basic.NeighboursTips);
	m_qSettings.setValue("SearchTips", quazaaSettings.Basic.SearchTips);
	m_qSettings.setValue("StartWithSystem", quazaaSettings.Basic.StartWithSystem);
	m_qSettings.setValue("TipDelay", quazaaSettings.Basic.TipDelay);
	m_qSettings.setValue("TipLowResMode", quazaaSettings.Basic.TipLowResMode);
	m_qSettings.setValue("TipTransparency", quazaaSettings.Basic.TipTransparency);
	m_qSettings.setValue("UploadsTips", quazaaSettings.Basic.UploadsTips);
	m_qSettings.endGroup();

	m_qSettings.beginGroup("Parental");
	m_qSettings.setValue("AdultFilter", quazaaSettings.Parental.AdultFilter);
	m_qSettings.setValue("ChatAdultCensor", quazaaSettings.Parental.ChatAdultCensor);
	m_qSettings.setValue("FilterAdultSearchResults", quazaaSettings.Parental.FilterAdultSearchResults);
	m_qSettings.endGroup();

	m_qSettings.beginGroup("Logging");
	m_qSettings.setValue("DebugLog", quazaaSettings.Logging.DebugLog);
	m_qSettings.setValue("LogLevel", quazaaSettings.Logging.LogLevel);
	m_qSettings.setValue("LogShowTimestamp", quazaaSettings.Logging.LogShowTimestamp);
	m_qSettings.setValue("MaxDebugLogSize", quazaaSettings.Logging.MaxDebugLogSize);
	m_qSettings.setValue("SearchLog", quazaaSettings.Logging.SearchLog);
	m_qSettings.endGroup();

	m_qSettings.beginGroup("Library");
	m_qSettings.setValue("FilterURI", quazaaSettings.Library.FilterURI);
	m_qSettings.setValue("GhostFiles", quazaaSettings.Library.GhostFiles);
	m_qSettings.setValue("HashWindow", quazaaSettings.Library.HashWindow);
	m_qSettings.setValue("HighPriorityHashing", quazaaSettings.Library.HighPriorityHashing);
	m_qSettings.setValue("HighPriorityHashingSpeed", quazaaSettings.Library.HighPriorityHashingSpeed);
	m_qSettings.setValue("HistoryDays", quazaaSettings.Library.HistoryDays);
	m_qSettings.setValue("HistoryTotal", quazaaSettings.Library.HistoryTotal);
	m_qSettings.setValue("LowPriorityHashingSpeed", quazaaSettings.Library.LowPriorityHashingSpeed);
	m_qSettings.setValue("NeverShareTypes", quazaaSettings.Library.NeverShareTypes);
	m_qSettings.setValue("PartialMatch", quazaaSettings.Library.PartialMatch);
	m_qSettings.setValue("PreferAPETags", quazaaSettings.Library.PreferAPETags);
	m_qSettings.setValue("QueryRouteSize", quazaaSettings.Library.QueryRouteSize);
	m_qSettings.setValue("RememberViews", quazaaSettings.Library.RememberViews);
	m_qSettings.setValue("SafeExecuteTypes", quazaaSettings.Library.SafeExecuteTypes);
	m_qSettings.setValue("ScanAPE", quazaaSettings.Library.ScanAPE);
	m_qSettings.setValue("ScanASF", quazaaSettings.Library.ScanASF);
	m_qSettings.setValue("ScanAVI", quazaaSettings.Library.ScanAVI);
	m_qSettings.setValue("ScanCHM", quazaaSettings.Library.ScanCHM);
	m_qSettings.setValue("ScanEXE", quazaaSettings.Library.ScanEXE);
	m_qSettings.setValue("ScanImage", quazaaSettings.Library.ScanImage);
	m_qSettings.setValue("ScanMP3", quazaaSettings.Library.ScanMP3);
	m_qSettings.setValue("ScanMPC", quazaaSettings.Library.ScanMPC);
	m_qSettings.setValue("ScanMPEG", quazaaSettings.Library.ScanMPEG);
	m_qSettings.setValue("ScanMSI", quazaaSettings.Library.ScanMSI);
	m_qSettings.setValue("ScanOGG", quazaaSettings.Library.ScanOGG);
	m_qSettings.setValue("ScanPDF", quazaaSettings.Library.ScanPDF);
	m_qSettings.setValue("SchemaURI", quazaaSettings.Library.SchemaURI);
	quazaaSettings.Library.Shares.removeDuplicates();
	m_qSettings.setValue("Shares", quazaaSettings.Library.Shares);
	m_qSettings.setValue("ShowCoverArt", quazaaSettings.Library.ShowCoverArt);
	m_qSettings.setValue("SmartSeriesDetection", quazaaSettings.Library.SmartSeriesDetection);
	m_qSettings.setValue("SourceExpire", quazaaSettings.Library.SourceExpire);
	m_qSettings.setValue("SourceMesh", quazaaSettings.Library.SourceMesh);
	m_qSettings.setValue("ThumbSize", quazaaSettings.Library.ThumbSize);
	m_qSettings.setValue("TigerHeight", quazaaSettings.Library.TigerHeight);
	m_qSettings.setValue("TreeSize", quazaaSettings.Library.TreeSize);
	m_qSettings.setValue("WatchFolders", quazaaSettings.Library.WatchFolders);
	m_qSettings.setValue("WatchFoldersTimeout", quazaaSettings.Library.WatchFoldersTimeout);
	m_qSettings.endGroup();

	m_qSettings.beginGroup("MediaPlayer");
	m_qSettings.setValue("Aspect", quazaaSettings.Media.Aspect);
	m_qSettings.setValue("AudioVisualPlugin", quazaaSettings.Media.AudioVisualPlugin);
	m_qSettings.setValue("CustomPlayerPath", quazaaSettings.Media.CustomPlayerPath);
	m_qSettings.setValue("MediaHandler", quazaaSettings.Media.Handler);
	m_qSettings.setValue("FileTypes", quazaaSettings.Media.FileTypes);
	m_qSettings.setValue("ListVisible", quazaaSettings.Media.ListVisible);
	m_qSettings.setValue("Mute", quazaaSettings.Media.Mute);
	m_qSettings.setValue("OpenPath", quazaaSettings.Media.OpenPath);
	m_qSettings.setValue("Playlist", quazaaSettings.Media.Playlist);
	m_qSettings.setValue("Shuffle", quazaaSettings.Media.Shuffle);
	m_qSettings.setValue("Repeat", quazaaSettings.Media.Repeat);
	m_qSettings.setValue("StatusVisible", quazaaSettings.Media.StatusVisible);
	m_qSettings.setValue("Volume", quazaaSettings.Media.Volume);
	m_qSettings.setValue("Zoom", quazaaSettings.Media.Zoom);
	m_qSettings.endGroup();

	m_qSettings.beginGroup("Search");
	m_qSettings.setValue("BlankSchemaURI", quazaaSettings.Search.BlankSchemaURI);
	m_qSettings.setValue("BrowseTreeSize", quazaaSettings.Search.BrowseTreeSize);
	m_qSettings.setValue("ClearPrevious", quazaaSettings.Search.ClearPrevious);
	m_qSettings.setValue("ExpandSearchMatches", quazaaSettings.Search.ExpandSearchMatches);
	m_qSettings.setValue("FilterMask", quazaaSettings.Search.FilterMask);
	m_qSettings.setValue("HighlightNew", quazaaSettings.Search.HighlightNew);
	m_qSettings.setValue("LastSchemaURI", quazaaSettings.Search.LastSchemaURI);
	m_qSettings.setValue("MaxPreviewLength", quazaaSettings.Search.MaxPreviewLength);
	m_qSettings.setValue("MonitorFilter", quazaaSettings.Search.MonitorFilter);
	m_qSettings.setValue("MonitorQueue", quazaaSettings.Search.MonitorQueue);
	m_qSettings.setValue("MonitorSchemaURI", quazaaSettings.Search.MonitorSchemaURI);
	m_qSettings.setValue("SchemaTypes", quazaaSettings.Search.SchemaTypes);
	m_qSettings.setValue("SearchThrottle", quazaaSettings.Search.Throttle);
	m_qSettings.setValue("ShareMonkeyBaseURL", quazaaSettings.Search.ShareMonkeyBaseURL);
	m_qSettings.setValue("ShowNames", quazaaSettings.Search.ShowNames);
	m_qSettings.setValue("SwitchOnDownload", quazaaSettings.Search.SwitchOnDownload);
	m_qSettings.endGroup();

	m_qSettings.beginGroup("Chat");
	m_qSettings.setValue("AwayMessageIdleTime", quazaaSettings.Chat.AwayMessageIdleTime);
	m_qSettings.setValue("Background", quazaaSettings.Chat.Background);
	m_qSettings.setValue("ConnectOnStartup", quazaaSettings.Chat.ConnectOnStartup);
	m_qSettings.setValue("ColorChatBackground", quazaaSettings.Chat.ColorChatBackground);
	m_qSettings.setValue("ColorNormalText", quazaaSettings.Chat.ColorNormalText);
	m_qSettings.setValue("ColorNoticesText", quazaaSettings.Chat.ColorNoticesText);
	m_qSettings.setValue("ColorRoomActionsText", quazaaSettings.Chat.ColorRoomActionsText);
	m_qSettings.setValue("ColorServerMessagesText", quazaaSettings.Chat.ColorServerMessagesText);
	m_qSettings.setValue("ColorTopicsText", quazaaSettings.Chat.ColorTopicsText);
	m_qSettings.setValue("EnableChatAllNetworks", quazaaSettings.Chat.EnableChatAllNetworks);
	m_qSettings.setValue("EnableFileTransfers", quazaaSettings.Chat.EnableFileTransfers);
	m_qSettings.setValue("GnutellaChatEnable", quazaaSettings.Chat.GnutellaChatEnable);
	m_qSettings.setValue("IrcServerName", quazaaSettings.Chat.IrcServerName);
	m_qSettings.setValue("IrcServerPort", quazaaSettings.Chat.IrcServerPort);
	m_qSettings.setValue("ScreenFont", quazaaSettings.Chat.ScreenFont);
	m_qSettings.setValue("ShowTimestamp", quazaaSettings.Chat.ShowTimestamp);
	m_qSettings.endGroup();

	m_qSettings.beginGroup("Connection");
	m_qSettings.setValue("DetectConnectionLoss", quazaaSettings.Connection.DetectConnectionLoss);
	m_qSettings.setValue("DetectConnectionReset", quazaaSettings.Connection.DetectConnectionReset);
	m_qSettings.setValue("FailureLimit", quazaaSettings.Connection.FailureLimit);
	m_qSettings.setValue("FailurePenalty", quazaaSettings.Connection.FailurePenalty);
	m_qSettings.setValue("InSpeed", quazaaSettings.Connection.InSpeed);
	m_qSettings.setValue("OutSpeed", quazaaSettings.Connection.OutSpeed);
	m_qSettings.setValue("Port", quazaaSettings.Connection.Port);
	m_qSettings.setValue("RandomPort", quazaaSettings.Connection.RandomPort);
	m_qSettings.setValue("SendBuffer", quazaaSettings.Connection.SendBuffer);
	m_qSettings.setValue("TimeoutConnect", quazaaSettings.Connection.TimeoutConnect);
	m_qSettings.setValue("TimeoutTraffic", quazaaSettings.Connection.TimeoutTraffic);
	m_qSettings.endGroup();

	m_qSettings.beginGroup("Web");
	m_qSettings.setValue("Ares", quazaaSettings.Web.Ares);
	m_qSettings.setValue("BrowserIntegration", quazaaSettings.Web.BrowserIntegration);
	m_qSettings.setValue("ED2K", quazaaSettings.Web.ED2K);
	m_qSettings.setValue("Foxy", quazaaSettings.Web.Foxy);
	m_qSettings.setValue("Gnutella", quazaaSettings.Web.Gnutella);
	m_qSettings.setValue("Magnet", quazaaSettings.Web.Magnet);
	m_qSettings.setValue("ManageDownloadTypes", quazaaSettings.Web.ManageDownloadTypes);
	m_qSettings.setValue("Piolet", quazaaSettings.Web.Piolet);
	m_qSettings.setValue("Torrent", quazaaSettings.Web.Torrent);
	m_qSettings.endGroup();

	m_qSettings.beginGroup("WebServices");
	m_qSettings.setValue("BitziAgent", quazaaSettings.WebServices.BitziAgent);
	m_qSettings.setValue("BitziOkay", quazaaSettings.WebServices.BitziOkay);
	m_qSettings.setValue("BitziWebSubmit", quazaaSettings.WebServices.BitziWebSubmit);
	m_qSettings.setValue("BitziWebView", quazaaSettings.WebServices.BitziWebView);
	m_qSettings.setValue("BitziXML", quazaaSettings.WebServices.BitziXML);
	m_qSettings.setValue("ShareMonkeyCid", quazaaSettings.WebServices.ShareMonkeyCid);
	m_qSettings.setValue("ShareMonkeyOkay", quazaaSettings.WebServices.ShareMonkeyOkay);
	m_qSettings.setValue("ShareMonkeySaveThumbnail", quazaaSettings.WebServices.ShareMonkeySaveThumbnail);
	m_qSettings.endGroup();

	m_qSettings.beginGroup("Transfers");
	m_qSettings.setValue("BandwidthDownloads", quazaaSettings.Transfers.BandwidthDownloads);
	m_qSettings.setValue("BandwidthHubIn", quazaaSettings.Transfers.BandwidthHubIn);
	m_qSettings.setValue("BandwidthHubOut", quazaaSettings.Transfers.BandwidthHubOut);
	m_qSettings.setValue("BandwidthHubUploads", quazaaSettings.Transfers.BandwidthHubUploads);
	m_qSettings.setValue("BandwidthLeafIn", quazaaSettings.Transfers.BandwidthLeafIn);
	m_qSettings.setValue("BandwidthLeafOut", quazaaSettings.Transfers.BandwidthLeafOut);
	m_qSettings.setValue("BandwidthPeerIn", quazaaSettings.Transfers.BandwidthPeerIn);
	m_qSettings.setValue("BandwidthPeerOut", quazaaSettings.Transfers.BandwidthPeerOut);
	m_qSettings.setValue("BandwidthRequest", quazaaSettings.Transfers.BandwidthRequest);
	m_qSettings.setValue("BandwidthUdpOut", quazaaSettings.Transfers.BandwidthUdpOut);
	m_qSettings.setValue("BandwidthUploads", quazaaSettings.Transfers.BandwidthUploads);
	m_qSettings.setValue("MinTransfersRest", quazaaSettings.Transfers.MinTransfersRest);
	m_qSettings.setValue("RatesUnit", quazaaSettings.Transfers.RatesUnit);
	m_qSettings.setValue("RequireConnectedNetwork", quazaaSettings.Transfers.RequireConnectedNetwork);
	m_qSettings.setValue("SimpleProgressBar", quazaaSettings.Transfers.SimpleProgressBar);
	m_qSettings.endGroup();

	m_qSettings.beginGroup("Downloads");
	m_qSettings.setValue("AllowBackwards", quazaaSettings.Downloads.AllowBackwards);
	m_qSettings.setValue("AutoClear", quazaaSettings.Downloads.AutoClear);
	m_qSettings.setValue("BufferSize", quazaaSettings.Downloads.BufferSize);
	m_qSettings.setValue("ChunkSize", quazaaSettings.Downloads.ChunkSize);
	m_qSettings.setValue("ChunkStrap", quazaaSettings.Downloads.ChunkStrap);
	m_qSettings.setValue("ClearDelay", quazaaSettings.Downloads.ClearDelay);
	m_qSettings.setValue("CompletePath", quazaaSettings.Downloads.CompletePath);
	m_qSettings.setValue("ConnectThrottle", quazaaSettings.Downloads.ConnectThrottle);
	m_qSettings.setValue("DropFailedSourcesThreshold", quazaaSettings.Downloads.DropFailedSourcesThreshold);
	m_qSettings.setValue("ExpandDownloads", quazaaSettings.Downloads.ExpandDownloads);
	m_qSettings.setValue("FlushSD", quazaaSettings.Downloads.FlushSD);
	m_qSettings.setValue("IncompletePath", quazaaSettings.Downloads.IncompletePath);
	m_qSettings.setValue("MaxAllowedFailures", quazaaSettings.Downloads.MaxAllowedFailures);
	m_qSettings.setValue("MaxConnectingSources", quazaaSettings.Downloads.MaxConnectingSources);
	m_qSettings.setValue("MaxFiles", quazaaSettings.Downloads.MaxFiles);
	m_qSettings.setValue("MaxFileSearches", quazaaSettings.Downloads.MaxFileSearches);
	m_qSettings.setValue("MaxReviews", quazaaSettings.Downloads.MaxReviews);
	m_qSettings.setValue("MaxTransfers", quazaaSettings.Downloads.MaxTransfers);
	m_qSettings.setValue("MaxTransfersPerFile", quazaaSettings.Downloads.MaxTransfersPerFile);
	m_qSettings.setValue("Metadata", quazaaSettings.Downloads.Metadata);
	m_qSettings.setValue("MinSources", quazaaSettings.Downloads.MinSources);
	m_qSettings.setValue("NeverDrop", quazaaSettings.Downloads.NeverDrop);
	m_qSettings.setValue("PushTimeout", quazaaSettings.Downloads.PushTimeout);
	m_qSettings.setValue("QueueLimit", quazaaSettings.Downloads.QueueLimit);
	m_qSettings.setValue("RequestHash", quazaaSettings.Downloads.RequestHash);
	m_qSettings.setValue("RequestHTTP11", quazaaSettings.Downloads.RequestHTTP11);
	m_qSettings.setValue("RequestURLENC", quazaaSettings.Downloads.RequestURLENC);
	m_qSettings.setValue("RetryDelay", quazaaSettings.Downloads.RetryDelay);
	m_qSettings.setValue("SaveInterval", quazaaSettings.Downloads.SaveInterval);
	m_qSettings.setValue("SearchPeriod", quazaaSettings.Downloads.SearchPeriod);
	m_qSettings.setValue("ShowGroups", quazaaSettings.Downloads.ShowGroups);
	m_qSettings.setValue("ShowMonitorURLs", quazaaSettings.Downloads.ShowMonitorURLs);
	m_qSettings.setValue("ShowPercent", quazaaSettings.Downloads.ShowPercent);
	m_qSettings.setValue("ShowSources", quazaaSettings.Downloads.ShowSources);
	m_qSettings.setValue("SortColumns", quazaaSettings.Downloads.SortColumns);
	m_qSettings.setValue("SortSources", quazaaSettings.Downloads.SortSources);
	m_qSettings.setValue("SourcesWanted", quazaaSettings.Downloads.SourcesWanted);
	m_qSettings.setValue("StaggardStart", quazaaSettings.Downloads.StaggardStart);
	m_qSettings.setValue("StarveGiveUp", quazaaSettings.Downloads.StarveGiveUp);
	m_qSettings.setValue("StarveTimeout", quazaaSettings.Downloads.StarveTimeout);
	m_qSettings.setValue("URIPrompt", quazaaSettings.Downloads.URIPrompt);
	m_qSettings.setValue("VerifyED2K", quazaaSettings.Downloads.VerifyED2K);
	m_qSettings.setValue("VerifyFiles", quazaaSettings.Downloads.VerifyFiles);
	m_qSettings.setValue("VerifyTiger", quazaaSettings.Downloads.VerifyTiger);
	m_qSettings.setValue("WebHookEnable", quazaaSettings.Downloads.WebHookEnable);
	m_qSettings.setValue("WebHookExtensions", quazaaSettings.Downloads.WebHookExtensions);
	m_qSettings.endGroup();

	m_qSettings.beginGroup("Uploads");
	m_qSettings.setValue("AllowBackwards", quazaaSettings.Uploads.AllowBackwards);
	m_qSettings.setValue("AutoClear", quazaaSettings.Uploads.AutoClear);
	m_qSettings.setValue("ClampdownFactor", quazaaSettings.Uploads.ClampdownFactor);
	m_qSettings.setValue("ClampdownFloor", quazaaSettings.Uploads.ClampdownFloor);
	m_qSettings.setValue("ClearDelay", quazaaSettings.Uploads.ClearDelay);
	m_qSettings.setValue("DynamicPreviews", quazaaSettings.Uploads.DynamicPreviews);
	m_qSettings.setValue("FreeBandwidthFactor", quazaaSettings.Uploads.FreeBandwidthFactor);
	m_qSettings.setValue("FreeBandwidthValue", quazaaSettings.Uploads.FreeBandwidthValue);
	m_qSettings.setValue("HubShareLimiting", quazaaSettings.Uploads.HubShareLimiting);
	m_qSettings.setValue("MaxPerHost", quazaaSettings.Uploads.MaxPerHost);
	m_qSettings.setValue("PreviewQuality", quazaaSettings.Uploads.PreviewQuality);
	m_qSettings.setValue("PreviewTransfers", quazaaSettings.Uploads.PreviewTransfers);
	m_qSettings.setValue("QueuePollMax", quazaaSettings.Uploads.QueuePollMax);
	m_qSettings.setValue("QueuePollMin", quazaaSettings.Uploads.QueuePollMin);
	m_qSettings.setValue("RewardQueuePercentage", quazaaSettings.Uploads.RewardQueuePercentage);
	m_qSettings.setValue("RotateChunkLimit", quazaaSettings.Uploads.RotateChunkLimit);
	m_qSettings.setValue("ShareHashset", quazaaSettings.Uploads.ShareHashset);
	m_qSettings.setValue("ShareMetadata", quazaaSettings.Uploads.ShareMetadata);
	m_qSettings.setValue("SharePartials", quazaaSettings.Uploads.SharePartials);
	m_qSettings.setValue("SharePreviews", quazaaSettings.Uploads.SharePreviews);
	m_qSettings.setValue("ShareTiger", quazaaSettings.Uploads.ShareTiger);
	m_qSettings.setValue("ThrottleMode", quazaaSettings.Uploads.ThrottleMode);
	m_qSettings.endGroup();

	m_qSettings.beginGroup("Security");
	m_qSettings.setValue("AllowProfileBrowse", quazaaSettings.Security.AllowProfileBrowse);
	m_qSettings.setValue("AllowSharesBrowse", quazaaSettings.Security.AllowSharesBrowse);
	m_qSettings.setValue("BlockedAgentUploadFilter", quazaaSettings.Security.BlockedAgentUploadFilter);
	m_qSettings.setValue("DeleteFirewallException", quazaaSettings.Security.DeleteFirewallException);
	m_qSettings.setValue("DeleteUPnPPorts", quazaaSettings.Security.DeleteUPnPPorts);
	m_qSettings.setValue("ED2kChatFilter", quazaaSettings.Security.ED2kChatFilter);
	m_qSettings.setValue("EnableFirewallException", quazaaSettings.Security.EnableFirewallException);
	m_qSettings.setValue("EnableUPnP", quazaaSettings.Security.EnableUPnP);
	m_qSettings.setValue("FirewallState", quazaaSettings.Security.FirewallState);
	m_qSettings.setValue("ChatFilter", quazaaSettings.Security.ChatFilter);
	m_qSettings.setValue("IrcFloodLimit", quazaaSettings.Security.IrcFloodLimit);
	m_qSettings.setValue("IrcFloodProtection", quazaaSettings.Security.IrcFloodProtection);
	m_qSettings.setValue("MaxMaliciousFileSize", quazaaSettings.Security.MaxMaliciousFileSize);
	m_qSettings.setValue("RemoteEnable", quazaaSettings.Security.RemoteEnable);
	m_qSettings.setValue("RemotePassword", quazaaSettings.Security.RemotePassword);
	m_qSettings.setValue("RemoteUsername", quazaaSettings.Security.RemoteUsername);
	m_qSettings.setValue("SearchIgnoreLocalIP", quazaaSettings.Security.SearchIgnoreLocalIP);
	m_qSettings.setValue("SearchIgnoreOwnIP", quazaaSettings.Security.SearchIgnoreOwnIP);
	m_qSettings.setValue("SearchSpamFilterThreshold", quazaaSettings.Security.SearchSpamFilterThreshold);
	m_qSettings.setValue("UPnPSkipWANIPSetup", quazaaSettings.Security.UPnPSkipWANIPSetup);
	m_qSettings.setValue("UPnPSkipWANPPPSetup", quazaaSettings.Security.UPnPSkipWANPPPSetup);
	m_qSettings.endGroup();

	m_qSettings.beginGroup("Gnutella");
	m_qSettings.setValue("CompressHub2Hub", quazaaSettings.Gnutella.CompressHub2Hub);
	m_qSettings.setValue("CompressHub2Leaf", quazaaSettings.Gnutella.CompressHub2Leaf);
	m_qSettings.setValue("CompressLeaf2Hub", quazaaSettings.Gnutella.CompressLeaf2Hub);
	m_qSettings.setValue("ConnectFactor", quazaaSettings.Gnutella.ConnectFactor);
	m_qSettings.setValue("ConnectThrottle", quazaaSettings.Gnutella.ConnectThrottle);
	m_qSettings.setValue("HitsPerPacket", quazaaSettings.Gnutella.HitsPerPacket);
	m_qSettings.setValue("HostCacheSize", quazaaSettings.Gnutella.HostCacheSize);
	m_qSettings.setValue("HostCacheView", quazaaSettings.Gnutella.HostCacheView);
	m_qSettings.setValue("MaxHits", quazaaSettings.Gnutella.MaxHits);
	m_qSettings.setValue("MaxResults", quazaaSettings.Gnutella.MaxResults);
	m_qSettings.setValue("RouteCache", quazaaSettings.Gnutella.RouteCache);
	m_qSettings.endGroup();

	m_qSettings.beginGroup("Gnutella2");
	m_qSettings.setValue("ClientMode", quazaaSettings.Gnutella2.ClientMode);
	m_qSettings.setValue("Enable", quazaaSettings.Gnutella2.Enable);
	m_qSettings.setValue("HAWPeriod", quazaaSettings.Gnutella2.HAWPeriod);
	m_qSettings.setValue("HostCount", quazaaSettings.Gnutella2.HostCount);
	m_qSettings.setValue("HostCurrent", quazaaSettings.Gnutella2.HostCurrent);
	m_qSettings.setValue("HostExpire", quazaaSettings.Gnutella2.HostExpire);
	m_qSettings.setValue("HubHorizonSize", quazaaSettings.Gnutella2.HubHorizonSize);
	m_qSettings.setValue("HubVerified", quazaaSettings.Gnutella2.HubVerified);
	m_qSettings.setValue("KHLHubCount", quazaaSettings.Gnutella2.KHLHubCount);
	m_qSettings.setValue("KHLPeriod", quazaaSettings.Gnutella2.KHLPeriod);
	m_qSettings.setValue("LNIPeriod", quazaaSettings.Gnutella2.LNIMinimumUpdate);
	m_qSettings.setValue("NumHubs", quazaaSettings.Gnutella2.NumHubs);
	m_qSettings.setValue("NumLeafs", quazaaSettings.Gnutella2.NumLeafs);
	m_qSettings.setValue("NumPeers", quazaaSettings.Gnutella2.NumPeers);
	m_qSettings.setValue("PingRate", quazaaSettings.Gnutella2.PingRate);
	m_qSettings.setValue("PingTimeout", quazaaSettings.Gnutella2.PingTimeout);
	m_qSettings.setValue("PingRelayLimit", quazaaSettings.Gnutella2.PingRelayLimit);
	m_qSettings.setValue("QueryHostDeadline", quazaaSettings.Gnutella2.QueryHostDeadline);
	m_qSettings.setValue("QueryHostThrottle", quazaaSettings.Gnutella2.QueryHostThrottle);
	m_qSettings.setValue("QueryKeyTime", quazaaSettings.Gnutella2.QueryKeyTime);
	m_qSettings.setValue("QueryLimit", quazaaSettings.Gnutella2.QueryLimit);
	m_qSettings.setValue("RequeryDelay", quazaaSettings.Gnutella2.RequeryDelay);
	m_qSettings.setValue("UdpBuffers", quazaaSettings.Gnutella2.UdpBuffers);
	m_qSettings.setValue("UdpInExpire", quazaaSettings.Gnutella2.UdpInExpire);
	m_qSettings.setValue("UdpInFrames", quazaaSettings.Gnutella2.UdpInFrames);
	m_qSettings.setValue("UdpMTU", quazaaSettings.Gnutella2.UdpMTU);
	m_qSettings.setValue("UdpOutExpire", quazaaSettings.Gnutella2.UdpOutExpire);
	m_qSettings.setValue("UdpOutFrames", quazaaSettings.Gnutella2.UdpOutFrames);
	m_qSettings.setValue("UdpOutResend", quazaaSettings.Gnutella2.UdpOutResend);
	m_qSettings.endGroup();

	m_qSettings.beginGroup("Ares");
	m_qSettings.setValue("Enable", quazaaSettings.Ares.Enable);
	m_qSettings.setValue("MaximumDownloads", quazaaSettings.Ares.MaximumDownloads);
	m_qSettings.setValue("MaximumUploads", quazaaSettings.Ares.MaximumUploads);
	m_qSettings.setValue("MaximumUploadsPerUser", quazaaSettings.Ares.MaximumUploadsPerUser);
	m_qSettings.endGroup();

	m_qSettings.beginGroup("eDonkey");
	m_qSettings.setValue("DefaultServerFlags", quazaaSettings.EDonkey.DefaultServerFlags);
	m_qSettings.setValue("DequeueTime", quazaaSettings.EDonkey.DequeueTime);
	m_qSettings.setValue("Enable", quazaaSettings.EDonkey.Enable);
	m_qSettings.setValue("EnableKad", quazaaSettings.EDonkey.EnableKad);
	m_qSettings.setValue("Endgame", quazaaSettings.EDonkey.Endgame);
	m_qSettings.setValue("ExtendedRequest", quazaaSettings.EDonkey.ExtendedRequest);
	m_qSettings.setValue("FastConnect", quazaaSettings.EDonkey.FastConnect);
	m_qSettings.setValue("ForceHighID", quazaaSettings.EDonkey.ForceHighID);
	m_qSettings.setValue("FrameSize", quazaaSettings.EDonkey.FrameSize);
	m_qSettings.setValue("GetSourcesThrottle", quazaaSettings.EDonkey.GetSourcesThrottle);
	m_qSettings.setValue("LargeFileSupport", quazaaSettings.EDonkey.LargeFileSupport);
	m_qSettings.setValue("LearnNewServers", quazaaSettings.EDonkey.LearnNewServers);
	m_qSettings.setValue("LearnNewServersClient", quazaaSettings.EDonkey.LearnNewServersClient);
	m_qSettings.setValue("MagnetSearch", quazaaSettings.EDonkey.MagnetSearch);
	m_qSettings.setValue("MaxClients", quazaaSettings.EDonkey.MaxClients);
	m_qSettings.setValue("MaxResults", quazaaSettings.EDonkey.MaxResults);
	m_qSettings.setValue("MaxShareCount", quazaaSettings.EDonkey.MaxShareCount);
	m_qSettings.setValue("MetAutoQuery", quazaaSettings.EDonkey.MetAutoQuery);
	m_qSettings.setValue("MinServerFileSize", quazaaSettings.EDonkey.MinServerFileSize);
	m_qSettings.setValue("NumServers", quazaaSettings.EDonkey.NumServers);
	m_qSettings.setValue("PacketThrottle", quazaaSettings.EDonkey.PacketThrottle);
	m_qSettings.setValue("QueryFileThrottle", quazaaSettings.EDonkey.QueryFileThrottle);
	m_qSettings.setValue("QueryGlobalThrottle", quazaaSettings.EDonkey.QueryGlobalThrottle);
	m_qSettings.setValue("QueueRankThrottle", quazaaSettings.EDonkey.QueueRankThrottle);
	m_qSettings.setValue("QueryServerThrottle", quazaaSettings.EDonkey.QueryServerThrottle);
	m_qSettings.setValue("ReAskTime", quazaaSettings.EDonkey.ReAskTime);
	m_qSettings.setValue("RequestPipe", quazaaSettings.EDonkey.RequestPipe);
	m_qSettings.setValue("RequestSize", quazaaSettings.EDonkey.RequestSize);
	m_qSettings.setValue("SearchCachedServers", quazaaSettings.EDonkey.SearchCachedServers);
	m_qSettings.setValue("SendPortServer", quazaaSettings.EDonkey.SendPortServer);
	m_qSettings.setValue("ServerListURL", quazaaSettings.EDonkey.ServerListURL);
	m_qSettings.setValue("ServerWalk", quazaaSettings.EDonkey.ServerWalk);
	m_qSettings.setValue("SourceThrottle", quazaaSettings.EDonkey.SourceThrottle);
	m_qSettings.setValue("StatsGlobalThrottle", quazaaSettings.EDonkey.StatsGlobalThrottle);
	m_qSettings.setValue("StatsServerThrottle", quazaaSettings.EDonkey.StatsServerThrottle);
	m_qSettings.endGroup();

	m_qSettings.beginGroup("BitTorrent");
	m_qSettings.setValue("AutoClear", quazaaSettings.BitTorrent.AutoClear);
	m_qSettings.setValue("AutoSeed", quazaaSettings.BitTorrent.AutoSeed);
	m_qSettings.setValue("BandwidthPercentage", quazaaSettings.BitTorrent.BandwidthPercentage);
	m_qSettings.setValue("ClearRatio", quazaaSettings.BitTorrent.ClearRatio);
	m_qSettings.setValue("CodePage", quazaaSettings.BitTorrent.CodePage);
	m_qSettings.setValue("DefaultTracker", quazaaSettings.BitTorrent.DefaultTracker);
	m_qSettings.setValue("DefaultTrackerPeriod", quazaaSettings.BitTorrent.DefaultTrackerPeriod);
	m_qSettings.setValue("DhtPruneTime", quazaaSettings.BitTorrent.DhtPruneTime);
	m_qSettings.setValue("DownloadConnections", quazaaSettings.BitTorrent.DownloadConnections);
	m_qSettings.setValue("DownloadTorrents", quazaaSettings.BitTorrent.DownloadTorrents);
	m_qSettings.setValue("Endgame", quazaaSettings.BitTorrent.Endgame);
	m_qSettings.setValue("ExtraKeys", quazaaSettings.BitTorrent.ExtraKeys);
	m_qSettings.setValue("LinkPing", quazaaSettings.BitTorrent.LinkPing);
	m_qSettings.setValue("LinkTimeout", quazaaSettings.BitTorrent.LinkTimeout);
	m_qSettings.setValue("Managed", quazaaSettings.BitTorrent.Managed);
	m_qSettings.setValue("PreferBTSources", quazaaSettings.BitTorrent.PreferBTSources);
	m_qSettings.setValue("RandomPeriod", quazaaSettings.BitTorrent.RandomPeriod);
	m_qSettings.setValue("RequestLimit", quazaaSettings.BitTorrent.RequestLimit);
	m_qSettings.setValue("RequestPipe", quazaaSettings.BitTorrent.RequestPipe);
	m_qSettings.setValue("RequestSize", quazaaSettings.BitTorrent.RequestSize);
	m_qSettings.setValue("ShowFilesInDownload", quazaaSettings.BitTorrent.ShowFilesInDownload);
	m_qSettings.setValue("SourceExchangePeriod", quazaaSettings.BitTorrent.SourceExchangePeriod);
	m_qSettings.setValue("StartPaused", quazaaSettings.BitTorrent.StartPaused);
	m_qSettings.setValue("TestPartials", quazaaSettings.BitTorrent.TestPartials);
	m_qSettings.setValue("TorrentPath", quazaaSettings.BitTorrent.TorrentPath);
	m_qSettings.setValue("TrackerKey", quazaaSettings.BitTorrent.TrackerKey);
	m_qSettings.setValue("UploadCount", quazaaSettings.BitTorrent.UploadCount);
	m_qSettings.setValue("UseKademlia", quazaaSettings.BitTorrent.UseKademlia);
	m_qSettings.setValue("UseSaveDialog", quazaaSettings.BitTorrent.UseSaveDialog);
	m_qSettings.setValue("UseTemp", quazaaSettings.BitTorrent.UseTemp);
	m_qSettings.endGroup();

	m_qSettings.beginGroup("Discovery");
	m_qSettings.setValue("AccessThrottle", quazaaSettings.Discovery.AccessThrottle);
	m_qSettings.setValue("BootstrapCount", quazaaSettings.Discovery.BootstrapCount);
	m_qSettings.setValue("CacheCount", quazaaSettings.Discovery.CacheCount);
	m_qSettings.setValue("DefaultUpdate", quazaaSettings.Discovery.DefaultUpdate);
	m_qSettings.setValue("EnableG1GWC", quazaaSettings.Discovery.EnableG1GWC);
	m_qSettings.setValue("FailureLimit", quazaaSettings.Discovery.FailureLimit);
	m_qSettings.setValue("Lowpoint", quazaaSettings.Discovery.Lowpoint);
	m_qSettings.setValue("UpdatePeriod", quazaaSettings.Discovery.UpdatePeriod);
	m_qSettings.endGroup();

	m_qSettings.beginGroup("Scheduler");

	m_qSettings.endGroup();
}

void QuazaaSettings::loadSettings()
{
	QSettings m_qSettings(quazaaGlobals.ApplicationOrganizationName(), quazaaGlobals.ApplicationName());

	m_qSettings.beginGroup("Live");
	quazaaSettings.Live.AdultWarning = m_qSettings.value("AdultWarning", false).toBool();
	quazaaSettings.Live.AutoClose = m_qSettings.value("AutoClose", false).toBool();
	quazaaSettings.Live.BandwidthScale = m_qSettings.value("BandwidthScale", 100).toInt();
	quazaaSettings.Live.DefaultED2KServersLoaded = m_qSettings.value("DefaultED2KServersLoaded", false).toBool();
	quazaaSettings.Live.DiskSpaceStop = m_qSettings.value("DiskSpaceStop", false).toBool();
	quazaaSettings.Live.DiskSpaceWarning = m_qSettings.value("DiskSpaceWarning", false).toBool();
	quazaaSettings.Live.DiskWriteWarning = m_qSettings.value("DiskWriteWarning", false).toBool();
	quazaaSettings.Live.DonkeyServerWarning = m_qSettings.value("DonkeyServerWarning", false).toBool();
	quazaaSettings.Live.LastDuplicateHash = m_qSettings.value("LastDuplicateHash", "").toString();
	quazaaSettings.Live.MaliciousWarning = m_qSettings.value("MaliciousWarning", false).toBool();
	quazaaSettings.Live.QueueLimitWarning = m_qSettings.value("QueueLimitWarning", false).toBool();
	quazaaSettings.Live.UploadLimitWarning = m_qSettings.value("UploadLimitWarning", false).toBool();
	m_qSettings.endGroup();

	m_qSettings.beginGroup("Basic");
	quazaaSettings.Basic.ChatTips = m_qSettings.value("ChatTips", true).toBool();
	quazaaSettings.Basic.CloseMode = m_qSettings.value("CloseMode", 0).toInt();
	quazaaSettings.Basic.ConnectOnStartup = m_qSettings.value("ConnectOnStartup", true).toBool();
	quazaaSettings.Basic.DiskSpaceStop = m_qSettings.value("DiskSpaceStop", 25).toInt();
	quazaaSettings.Basic.DiskSpaceWarning = m_qSettings.value("DiskSpaceWarning", 500).toInt();
	quazaaSettings.Basic.DownloadsTips = m_qSettings.value("DownloadsTips", true).toBool();
	quazaaSettings.Basic.LibraryTips = m_qSettings.value("LibraryTips", true).toBool();
	quazaaSettings.Basic.MediaTips = m_qSettings.value("MediaTips", true).toBool();
	quazaaSettings.Basic.MinimizeToTray = m_qSettings.value("MinimizeToTray", false).toBool();
	quazaaSettings.Basic.NeighboursTips = m_qSettings.value("NeighboursTips", true).toBool();
	quazaaSettings.Basic.SearchTips = m_qSettings.value("SearchTips", true).toBool();
	quazaaSettings.Basic.StartWithSystem = m_qSettings.value("StartWithSystem", false).toBool();
	quazaaSettings.Basic.TipDelay = m_qSettings.value("TipDelay", 600).toInt();
	quazaaSettings.Basic.TipLowResMode = m_qSettings.value("TipLowResMode", true).toBool();
	quazaaSettings.Basic.TipTransparency = m_qSettings.value("TipTransparency", 255).toInt();
	quazaaSettings.Basic.UploadsTips = m_qSettings.value("UploadsTips", true).toBool();
	m_qSettings.endGroup();

	m_qSettings.beginGroup("Parental");
	quazaaSettings.Parental.AdultFilter = m_qSettings.value("AdultFilter",
														 QStringList() << "shit" << "fuck" << "damn" << "bitch"
														 << "asshole" << "ass" << "pussy" << "cock" << "cunt" << "dick"
														 << "whore" << "slut" << "clit").toStringList();
	quazaaSettings.Parental.ChatAdultCensor = m_qSettings.value("ChatAdultCensor", true).toBool();
	quazaaSettings.Parental.FilterAdultSearchResults = m_qSettings.value("FilterAdultSearchResults", true).toBool();
	m_qSettings.endGroup();

	m_qSettings.beginGroup("Logging");
	quazaaSettings.Logging.DebugLog = m_qSettings.value("DebugLog", false).toBool();
	quazaaSettings.Logging.LogLevel = m_qSettings.value("LogLevel", 3).toInt();
	quazaaSettings.Logging.LogShowTimestamp = m_qSettings.value("LogShowTimestamp", true).toBool();
	quazaaSettings.Logging.MaxDebugLogSize = m_qSettings.value("MaxDebugLogSize", 10).toInt();
	quazaaSettings.Logging.SearchLog = m_qSettings.value("SearchLog", true).toBool();
	m_qSettings.endGroup();

	m_qSettings.beginGroup("Library");
	quazaaSettings.Library.FilterURI = m_qSettings.value("FilterURI", "").toString();
	quazaaSettings.Library.GhostFiles = m_qSettings.value("GhostFiles", true).toBool();
	quazaaSettings.Library.HashWindow = m_qSettings.value("HashWindow", true).toBool();
	quazaaSettings.Library.HighPriorityHashing = m_qSettings.value("HighPriorityHashing", false).toInt();
	quazaaSettings.Library.HighPriorityHashingSpeed = m_qSettings.value("HighPriorityHashingSpeed", 20).toBool();
	quazaaSettings.Library.HistoryDays = m_qSettings.value("HistoryDays", 3).toInt();
	quazaaSettings.Library.HistoryTotal = m_qSettings.value("HistoryTotal", 32).toInt();
	quazaaSettings.Library.LowPriorityHashingSpeed = m_qSettings.value("LowPriorityHashingSpeed", 2).toInt();
	quazaaSettings.Library.NeverShareTypes = m_qSettings.value("NeverShareTypes",
														 QStringList() << "vbs" << "js" << "jc!" << "fb!" << "bc!" << "!ut"
														 << "dbx" << "part" << "partial" << "pst" << "reget" << "getright"
														 << "pif" << "lnk" << "sd" << "url" << "wab" << "m4p" << "infodb"
														 << "racestats" << "chk" << "tmp" << "temp" << "ini" << "inf" << "log"
														 << "old" << "manifest" << "met" << "bak" << "$$$" << "---" << "~~~"
														 << "###" << "__incomplete___" << "wma" << "wmv").toStringList();
	quazaaSettings.Library.PartialMatch = m_qSettings.value("PartialMatch", true).toBool();
	quazaaSettings.Library.PreferAPETags = m_qSettings.value("PreferAPETags", true).toBool();
	quazaaSettings.Library.QueryRouteSize = m_qSettings.value("QueryRouteSize", 20).toInt();
	quazaaSettings.Library.RememberViews = m_qSettings.value("RememberViews", true).toBool();
	quazaaSettings.Library.SafeExecuteTypes = m_qSettings.value("SafeExecuteTypes",
														  QStringList() << "3gp" << "7z" << "aac" << "ace" << "ape" << "avi"
														  << "bmp" << "co" << "collection" << "flv" << "gif" << "iso"
														  << "jpg" << "jpeg" << "lit" << "mid" << "mov" << "m1v" << "m2v"
														  << "m3u" << "m4a" << "mkv" << "mp2" << "mp3" << "mp4" << "mpa"
														  << "mpe" << "mpg" << "mpeg" << "ogg" << "ogm" << "pdf" << "png"
														  << "qt" << "rar" << "rm" << "sks" << "tar" << "tgz" << "torrent"
														  << "txt" << "wav" << "zip").toStringList();
	quazaaSettings.Library.ScanAPE = m_qSettings.value("ScanAPE", true).toBool();
	quazaaSettings.Library.ScanASF = m_qSettings.value("ScanASF", true).toBool();
	quazaaSettings.Library.ScanAVI = m_qSettings.value("ScanAVI", true).toBool();
	quazaaSettings.Library.ScanCHM = m_qSettings.value("ScanCHM", true).toBool();
	quazaaSettings.Library.ScanEXE = m_qSettings.value("ScanEXE", true).toBool();
	quazaaSettings.Library.ScanImage = m_qSettings.value("ScanImage", true).toBool();
	quazaaSettings.Library.ScanMP3 = m_qSettings.value("ScanMP3", true).toBool();
	quazaaSettings.Library.ScanMPC = m_qSettings.value("ScanMPC", true).toBool();
	quazaaSettings.Library.ScanMPEG = m_qSettings.value("ScanMPEG", true).toBool();
	quazaaSettings.Library.ScanMSI = m_qSettings.value("ScanMSI", true).toBool();
	quazaaSettings.Library.ScanOGG = m_qSettings.value("ScanOGG", true).toBool();
	quazaaSettings.Library.ScanPDF = m_qSettings.value("ScanPDF", true).toBool();
	quazaaSettings.Library.SchemaURI = m_qSettings.value("SchemaURI", "http://www.limewire.com/schemas/audio.xsd").toString();
	quazaaSettings.Library.Shares = m_qSettings.value("Shares", QStringList() << QDesktopServices::storageLocation(QDesktopServices::DocumentsLocation).replace(QString("\\"), QString("/")) + "/Quazaa Downloads"
												<< QDesktopServices::storageLocation(QDesktopServices::HomeLocation) + "/Quazaa/Torrents").toStringList();
	quazaaSettings.Library.ShowCoverArt = m_qSettings.value("ShowCoverArt", true).toBool();
	quazaaSettings.Library.SmartSeriesDetection = m_qSettings.value("SmartSeriesDetection", false).toBool();
	quazaaSettings.Library.SourceExpire = m_qSettings.value("SourceExpire", 86400).toInt();
	quazaaSettings.Library.SourceMesh = m_qSettings.value("SourceMesh", true).toBool();
	quazaaSettings.Library.ThumbSize = m_qSettings.value("ThumbSize", 96).toInt();
	quazaaSettings.Library.TigerHeight = m_qSettings.value("TigerHeight", 9).toInt();
	quazaaSettings.Library.TreeSize = m_qSettings.value("TreeSize", 200).toInt();
	quazaaSettings.Library.WatchFolders = m_qSettings.value("WatchFolders", true).toBool();
	quazaaSettings.Library.WatchFoldersTimeout = m_qSettings.value("WatchFoldersTimeout", 5).toInt();
	m_qSettings.endGroup();

	m_qSettings.beginGroup("MediaPlayer");
	quazaaSettings.Media.Aspect = m_qSettings.value("Aspect", 0).toInt();
	quazaaSettings.Media.AudioVisualPlugin = m_qSettings.value("AudioVisualPlugin", "").toString();
	quazaaSettings.Media.CustomPlayerPath = m_qSettings.value("CustomPlayerPath", "").toString();
	quazaaSettings.Media.Handler = m_qSettings.value("MediaHandler", 0).toInt();
	quazaaSettings.Media.FileTypes = m_qSettings.value("FileTypes", QStringList() << "asx" << "wax" << "m3u" << "wvx" << "wmx"
													   << "asf" << "wav" << "snd" << "au" << "aif" << "aifc" << "aiff" << "mp3"
													   << "cda" << "mid" << "rmi" << "midi" << "avi" << "mpeg" << "mpg"
													   << "m1v" << "mp2" << "mpa" << "mpe").toStringList();
	quazaaSettings.Media.ListVisible = m_qSettings.value("ListVisible", true).toBool();
	quazaaSettings.Media.Mute = m_qSettings.value("Mute", false).toBool();
	quazaaSettings.Media.OpenPath = m_qSettings.value("OpenPath", QDesktopServices::storageLocation(QDesktopServices::DocumentsLocation).replace(QString("\\"), QString("/")) + "/Quazaa Downloads").toString();
	quazaaSettings.Media.Playlist = m_qSettings.value("Playlist", QStringList()).toStringList();
	quazaaSettings.Media.Shuffle = m_qSettings.value("Shuffle", false).toBool();
	quazaaSettings.Media.Repeat = m_qSettings.value("Repeat", false).toBool();
	quazaaSettings.Media.StatusVisible = m_qSettings.value("StatusVisible", true).toBool();
	quazaaSettings.Media.Volume = m_qSettings.value("Volume", 1.0).toReal();
	quazaaSettings.Media.Zoom = m_qSettings.value("Zoom", 0).toInt();
	m_qSettings.endGroup();

	m_qSettings.beginGroup("Search");
	quazaaSettings.Search.BlankSchemaURI = m_qSettings.value("BlankSchemaURI", "").toString();
	quazaaSettings.Search.BrowseTreeSize = m_qSettings.value("BrowseTreeSize", 180).toInt();
	quazaaSettings.Search.ClearPrevious = m_qSettings.value("ClearPrevious", 0).toInt();
	quazaaSettings.Search.ExpandSearchMatches = m_qSettings.value("ExpandSearchMatches", false).toBool();
	quazaaSettings.Search.FilterMask = m_qSettings.value("FilterMask", 360).toInt();
	quazaaSettings.Search.HighlightNew = m_qSettings.value("HighlightNew", true).toBool();
	quazaaSettings.Search.LastSchemaURI = m_qSettings.value("LastSchemaURI", "").toString();
	quazaaSettings.Search.MaxPreviewLength = m_qSettings.value("MaxPreviewLength", 20480).toInt();
	quazaaSettings.Search.MonitorFilter = m_qSettings.value("MonitorFilter", "").toString();
	quazaaSettings.Search.MonitorQueue = m_qSettings.value("MonitorQueue", 128).toInt();
	quazaaSettings.Search.MonitorSchemaURI = m_qSettings.value("MonitorSchemaURI", "http://www.limewire.com/schemas/audio.xsd").toString();
	quazaaSettings.Search.SchemaTypes = m_qSettings.value("SchemaTypes", true).toBool();
	quazaaSettings.Search.Throttle = m_qSettings.value("SearchThrottle", 200).toInt();
	quazaaSettings.Search.ShareMonkeyBaseURL = m_qSettings.value("ShareMonkeyBaseURL", "http://tools.sharemonkey.com/xml/").toString();
	quazaaSettings.Search.ShowNames = m_qSettings.value("ShowNames", true).toBool();
	quazaaSettings.Search.SwitchOnDownload = m_qSettings.value("SwitchOnDownload", true).toBool();
	m_qSettings.endGroup();

	m_qSettings.beginGroup("Chat");
	quazaaSettings.Chat.AwayMessageIdleTime = m_qSettings.value("AwayMessageIdleTime", 30).toInt();
	quazaaSettings.Chat.Background = m_qSettings.value("Background", "").toString();
	quazaaSettings.Chat.ConnectOnStartup = m_qSettings.value("ConnectOnStartup", false).toBool();
	quazaaSettings.Chat.ColorChatBackground = m_qSettings.value("ColorChatBackground", QColor(qRgb(255,255,255))).value<QColor>();
	quazaaSettings.Chat.ColorNormalText = m_qSettings.value("ColorNormalText", QColor(qRgb(0,0,0))).value<QColor>();
	quazaaSettings.Chat.ColorNoticesText = m_qSettings.value("ColorNoticesText", QColor(qRgb(255,0,0))).value<QColor>();
	quazaaSettings.Chat.ColorRoomActionsText = m_qSettings.value("ColorRoomActionsText", QColor(qRgb(0,170,0))).value<QColor>();
	quazaaSettings.Chat.ColorServerMessagesText = m_qSettings.value("ColorServerMessagesText", QColor(qRgb(0,0,255))).value<QColor>();
	quazaaSettings.Chat.ColorTopicsText = m_qSettings.value("ColorTopicsText", QColor(qRgb(170,85,127))).value<QColor>();
	quazaaSettings.Chat.EnableChatAllNetworks = m_qSettings.value("EnableChatAllNetworks", true).toBool();
	quazaaSettings.Chat.EnableFileTransfers = m_qSettings.value("EnableFileTransfers", true).toBool();
	quazaaSettings.Chat.GnutellaChatEnable = m_qSettings.value("GnutellaChatEnable", true).toBool();
	quazaaSettings.Chat.IrcServerName = m_qSettings.value("IrcServerName", "irc.p2pchat.net").toString();
	quazaaSettings.Chat.IrcServerPort = m_qSettings.value("IrcServerPort", 6667).toInt();
	quazaaSettings.Chat.ScreenFont = m_qSettings.value("ScreenFont", QFont()).value<QFont>();
	quazaaSettings.Chat.ShowTimestamp = m_qSettings.value("ShowTimestamp", false).toBool();
	m_qSettings.endGroup();

	m_qSettings.beginGroup("Connection");
	quazaaSettings.Connection.DetectConnectionLoss = m_qSettings.value("DetectConnectionLoss", true).toBool();
	quazaaSettings.Connection.DetectConnectionReset = m_qSettings.value("DetectConnectionReset", false).toBool();
	quazaaSettings.Connection.FailureLimit = m_qSettings.value("FailureLimit", 3).toInt();
	quazaaSettings.Connection.FailurePenalty = m_qSettings.value("FailurePenalty", 300).toInt();
	quazaaSettings.Connection.InSpeed = m_qSettings.value("InSpeed", 1024 * 1024).toULongLong(); // 1Mbit
	quazaaSettings.Connection.OutSpeed = m_qSettings.value("OutSpeed", 16384).toULongLong();	 // 16KB/s
	quazaaSettings.Connection.Port = m_qSettings.value("Port", 6350).toUInt();
	quazaaSettings.Connection.RandomPort = m_qSettings.value("RandomPort", false).toBool();
	quazaaSettings.Connection.SendBuffer = m_qSettings.value("SendBuffer", 2048).toUInt();
	quazaaSettings.Connection.TimeoutConnect = m_qSettings.value("TimeoutConnect", 16).toUInt();
	quazaaSettings.Connection.TimeoutTraffic = m_qSettings.value("TimeoutTraffic", 60).toUInt();
	m_qSettings.endGroup();

	m_qSettings.beginGroup("Web");
	quazaaSettings.Web.BrowserIntegration = m_qSettings.value("BrowserIntegration", false).toBool();
	quazaaSettings.Web.Ares = m_qSettings.value("Ares", true).toBool();
	quazaaSettings.Web.ED2K = m_qSettings.value("ED2K", true).toBool();
	quazaaSettings.Web.Foxy = m_qSettings.value("Foxy", true).toBool();
	quazaaSettings.Web.Gnutella = m_qSettings.value("Gnutella", true).toBool();
	quazaaSettings.Web.Magnet = m_qSettings.value("Magnet", true).toBool();
	quazaaSettings.Web.ManageDownloadTypes = m_qSettings.value("ManageDownloadTypes", QStringList() << "7z" << "ace" << "arj"
														 << "bin" << "exe" << "fml" << "grs" << "gz" << "hqx" << "iso"
														 << "lzh" << "mp3" << "msi" << "r0" << "rar" << "sit" << "tar"
														 << "tgz" << "z" << "zip").toStringList();
	quazaaSettings.Web.Piolet = m_qSettings.value("Piolet", true).toBool();
	quazaaSettings.Web.Torrent = m_qSettings.value("Torrent", true).toBool();
	m_qSettings.endGroup();

	m_qSettings.beginGroup("WebServices");
	quazaaSettings.WebServices.BitziAgent = m_qSettings.value("BitziAgent", ".").toString();
	quazaaSettings.WebServices.BitziOkay = m_qSettings.value("BitziOkay", false).toBool();
	quazaaSettings.WebServices.BitziWebSubmit = m_qSettings.value("BitziWebSubmit", "http://bitzi.com/lookup/(SHA1).(TTH)?fl=(SIZE)&ff=(FIRST20)&fn=(NAME)&tag.ed2k.ed2khash=(ED2K)&(INFO)&a=(AGENT)&v=Q0.4&ref=quazaa").toString();
	quazaaSettings.WebServices.BitziWebView = m_qSettings.value("BitziWebView", "http://bitzi.com/lookup/(URN)?v=detail&ref=quazaa").toString();
	quazaaSettings.WebServices.BitziXML = m_qSettings.value("BitziXML", "http://ticket.bitzi.com/rdf/(SHA1).(TTH)").toString();
	quazaaSettings.WebServices.ShareMonkeyCid = m_qSettings.value("ShareMonkeyCid", "197506").toString();
	quazaaSettings.WebServices.ShareMonkeyOkay = m_qSettings.value("ShareMonkeyOkay", false).toBool();
	quazaaSettings.WebServices.ShareMonkeySaveThumbnail = m_qSettings.value("ShareMonkeySaveThumbnail", false).toBool();
	m_qSettings.endGroup();

	m_qSettings.beginGroup("Transfers");
	quazaaSettings.Transfers.BandwidthDownloads = m_qSettings.value("Downloads", 1500.0).toDouble();
	quazaaSettings.Transfers.BandwidthHubIn = m_qSettings.value("HubIn", 0).toInt();
	quazaaSettings.Transfers.BandwidthHubOut = m_qSettings.value("HubOut", 0).toInt();
	quazaaSettings.Transfers.BandwidthHubUploads = m_qSettings.value("HubUploads", 40).toInt();
	quazaaSettings.Transfers.BandwidthLeafIn = m_qSettings.value("LeafIn", 0).toInt();
	quazaaSettings.Transfers.BandwidthLeafOut = m_qSettings.value("LeafOut", 0).toInt();
	quazaaSettings.Transfers.BandwidthPeerIn = m_qSettings.value("PeerIn", 0).toInt();
	quazaaSettings.Transfers.BandwidthPeerOut = m_qSettings.value("PeerOut", 0).toInt();
	quazaaSettings.Transfers.BandwidthRequest = m_qSettings.value("Request", 32).toInt();
	quazaaSettings.Transfers.BandwidthUdpOut = m_qSettings.value("UdpOut", 0).toInt();
	quazaaSettings.Transfers.BandwidthUploads = m_qSettings.value("Uploads", 384.0).toDouble();
	quazaaSettings.Transfers.MinTransfersRest = m_qSettings.value("MinTransfersRest", 15).toInt();
	quazaaSettings.Transfers.RatesUnit = m_qSettings.value("RatesUnit", 1).toInt();
	quazaaSettings.Transfers.RequireConnectedNetwork = m_qSettings.value("RequireConnectedNetwork", true).toBool();
	quazaaSettings.Transfers.SimpleProgressBar = m_qSettings.value("SimpleProgressBar", false).toBool();
	m_qSettings.endGroup();

	m_qSettings.beginGroup("Downloads");
	quazaaSettings.Downloads.AllowBackwards = m_qSettings.value("AllowBackwards", true).toBool();
	quazaaSettings.Downloads.AutoClear = m_qSettings.value("AutoClear", false).toBool();
	quazaaSettings.Downloads.BufferSize = m_qSettings.value("BufferSize", 81920).toInt();
	quazaaSettings.Downloads.ChunkSize = m_qSettings.value("ChunkSize", 524288).toInt();
	quazaaSettings.Downloads.ChunkStrap = m_qSettings.value("ChunkStrap", 131072).toInt();
	quazaaSettings.Downloads.ClearDelay = m_qSettings.value("ClearDelay", 30000).toInt();
	quazaaSettings.Downloads.CompletePath = m_qSettings.value("CompletePath", QDesktopServices::storageLocation(QDesktopServices::DocumentsLocation).replace(QString("\\"), QString("/")) + "/Quazaa Downloads").toString();
	quazaaSettings.Downloads.ConnectThrottle = m_qSettings.value("ConnectThrottle", 800).toInt();
	quazaaSettings.Downloads.DropFailedSourcesThreshold = m_qSettings.value("DropFailedSourcesThreshold", 20).toInt();
	quazaaSettings.Downloads.ExpandDownloads = m_qSettings.value("ExpandDownloads", false).toBool();
	quazaaSettings.Downloads.FlushSD = m_qSettings.value("FlushSD", true).toBool();
	quazaaSettings.Downloads.IncompletePath = m_qSettings.value("IncompletePath", QDesktopServices::storageLocation(QDesktopServices::HomeLocation) + "/Quazaa/Incomplete").toString();
	quazaaSettings.Downloads.MaxAllowedFailures = m_qSettings.value("MaxAllowedFailures", 10).toInt();
	quazaaSettings.Downloads.MaxConnectingSources = m_qSettings.value("MaxConnectingSources", 8).toInt();
	quazaaSettings.Downloads.MaxFiles = m_qSettings.value("MaxFiles", 26).toInt();
	quazaaSettings.Downloads.MaxFileSearches = m_qSettings.value("MaxFileSearches", 2).toInt();
	quazaaSettings.Downloads.MaxReviews = m_qSettings.value("MaxReviews", 64).toInt();
	quazaaSettings.Downloads.MaxTransfers = m_qSettings.value("MaxTransfers", 100).toInt();
	quazaaSettings.Downloads.MaxTransfersPerFile = m_qSettings.value("MaxTransfersPerFile", 10).toInt();
	quazaaSettings.Downloads.Metadata = m_qSettings.value("Metadata", true).toBool();
	quazaaSettings.Downloads.MinSources = m_qSettings.value("MinSources", 1).toInt();
	quazaaSettings.Downloads.NeverDrop = m_qSettings.value("NeverDrop", false).toBool();
	quazaaSettings.Downloads.PushTimeout = m_qSettings.value("PushTimeout", 45000).toInt();
	quazaaSettings.Downloads.QueueLimit = m_qSettings.value("QueueLimit", 3).toInt();
	quazaaSettings.Downloads.RequestHash = m_qSettings.value("RequestHash", true).toBool();
	quazaaSettings.Downloads.RequestHTTP11 = m_qSettings.value("RequestHTTP11", true).toBool();
	quazaaSettings.Downloads.RequestURLENC = m_qSettings.value("RequestURLENC", true).toBool();
	quazaaSettings.Downloads.RetryDelay = m_qSettings.value("RetryDelay", 600000).toInt();
	quazaaSettings.Downloads.SaveInterval = m_qSettings.value("SaveInterval", 60000).toInt();
	quazaaSettings.Downloads.SearchPeriod = m_qSettings.value("SearchPeriod", 120000).toInt();
	quazaaSettings.Downloads.ShowPercent = m_qSettings.value("ShowPercent", false).toBool();
	quazaaSettings.Downloads.ShowSources = m_qSettings.value("ShowSources", false).toBool();
	quazaaSettings.Downloads.SortColumns = m_qSettings.value("SortColumns", true).toBool();
	quazaaSettings.Downloads.SortSources = m_qSettings.value("SortSources", true).toBool();
	quazaaSettings.Downloads.SourcesWanted = m_qSettings.value("SourcesWanted", 500).toInt();
	quazaaSettings.Downloads.StaggardStart = m_qSettings.value("StaggardStart", false).toBool();
	quazaaSettings.Downloads.StarveGiveUp = m_qSettings.value("StarveGiveUp", 3).toInt();
	quazaaSettings.Downloads.StarveTimeout = m_qSettings.value("StarveTimeout", 2700).toInt();
	quazaaSettings.Downloads.URIPrompt = m_qSettings.value("URIPrompt", true).toBool();
	quazaaSettings.Downloads.VerifyED2K = m_qSettings.value("VerifyED2K", true).toBool();
	quazaaSettings.Downloads.VerifyFiles = m_qSettings.value("VerifyFiles", true).toBool();
	quazaaSettings.Downloads.VerifyTiger = m_qSettings.value("VerifyTiger", true).toBool();
	m_qSettings.endGroup();

	m_qSettings.beginGroup("Uploads");
	quazaaSettings.Uploads.AllowBackwards = m_qSettings.value("AllowBackwards", true).toBool();
	quazaaSettings.Uploads.AutoClear = m_qSettings.value("AutoClear", false).toBool();
	quazaaSettings.Uploads.ClampdownFactor = m_qSettings.value("ClampdownFactor", 20).toInt();
	quazaaSettings.Uploads.ClampdownFloor = m_qSettings.value("SharePartials", 8).toInt();
	quazaaSettings.Uploads.ClearDelay = m_qSettings.value("ClearDelay", 30).toInt();
	quazaaSettings.Uploads.DynamicPreviews = m_qSettings.value("DynamicPreviews", true).toBool();
	quazaaSettings.Uploads.FreeBandwidthFactor = m_qSettings.value("FreeBandwidthFactor", 15).toInt();
	quazaaSettings.Uploads.FreeBandwidthValue = m_qSettings.value("FreeBandwidthValue", 20).toInt();
	quazaaSettings.Uploads.HubShareLimiting = m_qSettings.value("HubShareLimiting", true).toBool();
	quazaaSettings.Uploads.MaxPerHost = m_qSettings.value("MaxPerHost", 2).toInt();
	quazaaSettings.Uploads.PreviewQuality = m_qSettings.value("PreviewQuality", 70).toInt();
	quazaaSettings.Uploads.PreviewTransfers = m_qSettings.value("PreviewTransfers", 3).toInt();
	quazaaSettings.Uploads.QueuePollMax = m_qSettings.value("QueuePollMax", 120000).toInt();
	quazaaSettings.Uploads.QueuePollMin = m_qSettings.value("QueuePollMin", 45000).toInt();
	quazaaSettings.Uploads.RewardQueuePercentage = m_qSettings.value("RewardQueuePercentage", 10).toInt();
	quazaaSettings.Uploads.RotateChunkLimit = m_qSettings.value("RotateChunkLimit", 1024).toInt();
	quazaaSettings.Uploads.ShareHashset = m_qSettings.value("ShareHashset", true).toBool();
	quazaaSettings.Uploads.ShareMetadata = m_qSettings.value("ShareMetadata", true).toBool();
	quazaaSettings.Uploads.SharePartials = m_qSettings.value("SharePartials", true).toBool();
	quazaaSettings.Uploads.SharePreviews = m_qSettings.value("SharePreviews", true).toBool();
	quazaaSettings.Uploads.ShareTiger = m_qSettings.value("ShareTiger", true).toBool();
	quazaaSettings.Uploads.ThrottleMode = m_qSettings.value("ThrottleMode", true).toBool();
	m_qSettings.endGroup();

	m_qSettings.beginGroup("Security");
	quazaaSettings.Security.AllowProfileBrowse = m_qSettings.value("AllowProfileBrowse", true).toBool();
	quazaaSettings.Security.AllowSharesBrowse = m_qSettings.value("AllowSharesBrowse", true).toBool();
	quazaaSettings.Security.BlockedAgentUploadFilter = m_qSettings.value("BlockedAgentUploadFilter", QStringList() << "Mozilla").toStringList();
	quazaaSettings.Security.DeleteFirewallException = m_qSettings.value("DeleteFirewallException", true).toBool();
	quazaaSettings.Security.DeleteUPnPPorts = m_qSettings.value("DeleteUPnPPorts", true).toBool();
	quazaaSettings.Security.ED2kChatFilter = m_qSettings.value("ED2kChatFilter", true).toBool();
	quazaaSettings.Security.EnableFirewallException = m_qSettings.value("EnableFirewallException", true).toBool();
	quazaaSettings.Security.EnableUPnP = m_qSettings.value("EnableUPnP", true).toBool();
	quazaaSettings.Security.FirewallState = m_qSettings.value("FirewallState", 0).toInt();
	quazaaSettings.Security.ChatFilter = m_qSettings.value("ChatFilter", true).toBool();
	quazaaSettings.Security.IrcFloodLimit = m_qSettings.value("IrcFloodLimit", 24).toInt();
	quazaaSettings.Security.IrcFloodProtection = m_qSettings.value("IrcFloodProtection", true).toBool();
	quazaaSettings.Security.RemoteEnable = m_qSettings.value("RemoteEnable", false).toBool();
	quazaaSettings.Security.RemotePassword = m_qSettings.value("RemotePassword", "").toString();
	quazaaSettings.Security.RemoteUsername = m_qSettings.value("RemoteUsername", "").toString();
	quazaaSettings.Security.SearchIgnoreLocalIP = m_qSettings.value("SearchIgnoreLocalIP", true).toBool();
	quazaaSettings.Security.SearchIgnoreOwnIP = m_qSettings.value("SearchIgnoreOwnIP", true).toBool();
	quazaaSettings.Security.SearchSpamFilterThreshold = m_qSettings.value("SearchSpamFilterThreshold", 20).toInt();
	quazaaSettings.Security.UPnPSkipWANIPSetup = m_qSettings.value("UPnPSkipWANIPSetup", false).toBool();
	quazaaSettings.Security.UPnPSkipWANPPPSetup = m_qSettings.value("UPnPSkipWANPPPSetup", false).toBool();
	m_qSettings.endGroup();

	m_qSettings.beginGroup("Gnutella");
	quazaaSettings.Gnutella.CompressHub2Hub = m_qSettings.value("CompressHub2Hub", true).toBool();
	quazaaSettings.Gnutella.CompressHub2Leaf = m_qSettings.value("CompressHub2Leaf", true).toBool();
	quazaaSettings.Gnutella.CompressLeaf2Hub = m_qSettings.value("CompressLeaf2Hub", false).toBool();
	quazaaSettings.Gnutella.ConnectFactor = m_qSettings.value("ConnectFactor", 3).toInt();
	quazaaSettings.Gnutella.ConnectThrottle = m_qSettings.value("ConnectThrottle", 120).toInt();
	quazaaSettings.Gnutella.HitsPerPacket = m_qSettings.value("HitsPerPacket", 64).toInt();
	quazaaSettings.Gnutella.HostCacheSize = m_qSettings.value("HostCacheSize", 1024).toInt();
	quazaaSettings.Gnutella.HostCacheView = m_qSettings.value("HostCacheView", 3).toInt();
	quazaaSettings.Gnutella.MaxHits = m_qSettings.value("MaxHits", 64).toInt();
	quazaaSettings.Gnutella.MaxResults = m_qSettings.value("MaxResults", 150).toInt();
	quazaaSettings.Gnutella.RouteCache = m_qSettings.value("RouteCache", 10).toInt();
	m_qSettings.endGroup();

	m_qSettings.beginGroup("Gnutella2");
	quazaaSettings.Gnutella2.ClientMode = m_qSettings.value("ClientMode", 0).toInt();
	quazaaSettings.Gnutella2.Enable = m_qSettings.value("Enable", true).toBool();
	quazaaSettings.Gnutella2.HAWPeriod = m_qSettings.value("HAWPeriod", 300).toInt();
	quazaaSettings.Gnutella2.HostCount = m_qSettings.value("HostCount", 15).toInt();
	quazaaSettings.Gnutella2.HostCurrent = m_qSettings.value("HostCurrent", 600).toInt();
	quazaaSettings.Gnutella2.HostExpire = m_qSettings.value("HostExpire", 172800).toInt();
	quazaaSettings.Gnutella2.HubHorizonSize = m_qSettings.value("HubHorizonSize", 128).toInt();
	quazaaSettings.Gnutella2.HubVerified = m_qSettings.value("HubVerified", false).toBool();
	quazaaSettings.Gnutella2.KHLHubCount = m_qSettings.value("KHLHubCount", 50).toInt();
	quazaaSettings.Gnutella2.KHLPeriod = m_qSettings.value("KHLPeriod", 60).toInt();
	quazaaSettings.Gnutella2.LNIMinimumUpdate = m_qSettings.value("LNIMinimumUpdate", 60).toInt();
	quazaaSettings.Gnutella2.NumHubs = m_qSettings.value("NumHubs", 3).toInt();
	quazaaSettings.Gnutella2.NumLeafs = m_qSettings.value("NumLeafs", 300).toInt();
	quazaaSettings.Gnutella2.NumPeers = m_qSettings.value("NumPeers", 6).toInt();
	quazaaSettings.Gnutella2.PingRate = m_qSettings.value("PingRate", 120).toInt();
	quazaaSettings.Gnutella2.PingTimeout = m_qSettings.value("PingTimeout", 120).toUInt();
	quazaaSettings.Gnutella2.PingRelayLimit = m_qSettings.value("PingRelayLimit", 10).toInt();
	quazaaSettings.Gnutella2.QueryHostDeadline = m_qSettings.value("QueryHostDeadline", 600).toInt();
	quazaaSettings.Gnutella2.QueryHostThrottle = m_qSettings.value("QueryHostThrottle", 300).toInt();
	quazaaSettings.Gnutella2.QueryKeyTime = m_qSettings.value("QueryKeyTime", 1800).toInt();
	quazaaSettings.Gnutella2.QueryLimit = m_qSettings.value("QueryLimit", 2400).toInt();
	quazaaSettings.Gnutella2.RequeryDelay = m_qSettings.value("RequeryDelay", 14400).toInt();
	quazaaSettings.Gnutella2.UdpBuffers = m_qSettings.value("UdpBuffers", 512).toInt();
	quazaaSettings.Gnutella2.UdpInExpire = m_qSettings.value("UdpInExpire", 30).toInt();
	quazaaSettings.Gnutella2.UdpInFrames = m_qSettings.value("UdpInFrames", 256).toInt();
	quazaaSettings.Gnutella2.UdpMTU = m_qSettings.value("UdpMTU", 500).toInt();
	quazaaSettings.Gnutella2.UdpOutExpire = m_qSettings.value("UdpOutExpire", 26).toInt();
	quazaaSettings.Gnutella2.UdpOutFrames = m_qSettings.value("UdpOutFrames", 256).toInt();
	quazaaSettings.Gnutella2.UdpOutResend = m_qSettings.value("UdpOutResend", 6).toInt();
	m_qSettings.endGroup();

	m_qSettings.beginGroup("Ares");
	quazaaSettings.Ares.Enable = m_qSettings.value("Enable", true).toBool();
	quazaaSettings.Ares.MaximumDownloads = m_qSettings.value("MaximumDownloads", 10).toInt();
	quazaaSettings.Ares.MaximumUploads = m_qSettings.value("MaximumUploads", 6).toInt();
	quazaaSettings.Ares.MaximumUploadsPerUser = m_qSettings.value("MaximumUploadsPerUser", 3).toInt();
	m_qSettings.endGroup();

	m_qSettings.beginGroup("eDonkey");
	quazaaSettings.EDonkey.DefaultServerFlags = m_qSettings.value("DefaultServerFlags", "ffffffff").toString();
	quazaaSettings.EDonkey.DequeueTime = m_qSettings.value("DequeueTime", 60).toInt();
	quazaaSettings.EDonkey.Enable = m_qSettings.value("Enable", false).toBool();
	quazaaSettings.EDonkey.EnableKad = m_qSettings.value("EnableKad", false).toBool();
	quazaaSettings.EDonkey.Endgame = m_qSettings.value("Endgame", true).toBool();
	quazaaSettings.EDonkey.ExtendedRequest = m_qSettings.value("ExtendedRequest", 2).toInt();
	quazaaSettings.EDonkey.FastConnect = m_qSettings.value("FastConnect", false).toBool();
	quazaaSettings.EDonkey.ForceHighID = m_qSettings.value("ForceHighID", true).toBool();
	quazaaSettings.EDonkey.FrameSize = m_qSettings.value("FrameSize", 10).toInt();
	quazaaSettings.EDonkey.GetSourcesThrottle = m_qSettings.value("GetSourcesThrottle", 8).toInt();
	quazaaSettings.EDonkey.LargeFileSupport = m_qSettings.value("LargeFileSupport", false).toBool();
	quazaaSettings.EDonkey.LearnNewServers = m_qSettings.value("LearnNewServers", false).toBool();
	quazaaSettings.EDonkey.LearnNewServersClient = m_qSettings.value("LearnNewServersClient", false).toBool();
	quazaaSettings.EDonkey.MagnetSearch = m_qSettings.value("MagnetSearch", true).toBool();
	quazaaSettings.EDonkey.MaxClients = m_qSettings.value("MaxClients", 35).toInt();
	quazaaSettings.EDonkey.MaxResults = m_qSettings.value("MaxResults", 100).toInt();
	quazaaSettings.EDonkey.MaxShareCount = m_qSettings.value("MaxShareCount", 1000).toInt();
	quazaaSettings.EDonkey.MetAutoQuery = m_qSettings.value("MetAutoQuery", true).toBool();
	quazaaSettings.EDonkey.MinServerFileSize = m_qSettings.value("MinServerFileSize", 0).toInt();
	quazaaSettings.EDonkey.NumServers = m_qSettings.value("NumServers", 1).toInt();
	quazaaSettings.EDonkey.PacketThrottle = m_qSettings.value("PacketThrottle", 500).toInt();
	quazaaSettings.EDonkey.QueryFileThrottle = m_qSettings.value("QueryFileThrottle", 60).toInt();
	quazaaSettings.EDonkey.QueryGlobalThrottle = m_qSettings.value("QueryGlobalThrottle", 1000).toInt();
	quazaaSettings.EDonkey.QueueRankThrottle = m_qSettings.value("QueueRankThrottle", 120).toInt();
	quazaaSettings.EDonkey.QueryServerThrottle = m_qSettings.value("QueryServerThrottle", 120).toInt();
	quazaaSettings.EDonkey.ReAskTime = m_qSettings.value("ReAskTime", 29).toInt();
	quazaaSettings.EDonkey.RequestPipe = m_qSettings.value("RequestPipe", 3).toInt();
	quazaaSettings.EDonkey.RequestSize = m_qSettings.value("RequestSize", 90).toInt();
	quazaaSettings.EDonkey.SearchCachedServers = m_qSettings.value("SearchCachedServers", true).toBool();
	quazaaSettings.EDonkey.SendPortServer = m_qSettings.value("SendPortServer", false).toBool();
	quazaaSettings.EDonkey.ServerListURL = m_qSettings.value("ServerListURL", "http://ocbmaurice.dyndns.org/pl/slist.pl/server.met?download/server-best.met").toString();
	quazaaSettings.EDonkey.ServerWalk = m_qSettings.value("ServerWalk", true).toBool();
	quazaaSettings.EDonkey.SourceThrottle = m_qSettings.value("SourceThrottle", 1000).toInt();
	quazaaSettings.EDonkey.StatsGlobalThrottle = m_qSettings.value("StatsGlobalThrottle", 30).toInt();
	quazaaSettings.EDonkey.StatsServerThrottle = m_qSettings.value("StatsServerThrottle", 7).toInt();
	m_qSettings.endGroup();

	m_qSettings.beginGroup("BitTorrent");
	quazaaSettings.BitTorrent.AutoClear = m_qSettings.value("AutoClear", false).toBool();
	quazaaSettings.BitTorrent.AutoSeed = m_qSettings.value("AutoSeed", true).toBool();
	quazaaSettings.BitTorrent.BandwidthPercentage = m_qSettings.value("BandwidthPercentage", 80).toInt();
	quazaaSettings.BitTorrent.ClearRatio = m_qSettings.value("ClearRatio", 120).toInt();
	quazaaSettings.BitTorrent.CodePage = m_qSettings.value("CodePage", 0).toInt();
	quazaaSettings.BitTorrent.DefaultTracker = m_qSettings.value("DefaultTracker", "").toString();
	quazaaSettings.BitTorrent.DefaultTrackerPeriod = m_qSettings.value("DefaultTrackerPeriod", 5).toInt();
	quazaaSettings.BitTorrent.DhtPruneTime = m_qSettings.value("DhtPruneTime", 30).toInt();
	quazaaSettings.BitTorrent.DownloadConnections = m_qSettings.value("DownloadConnections", 40).toInt();
	quazaaSettings.BitTorrent.DownloadTorrents = m_qSettings.value("DownloadTorrents", 4).toInt();
	quazaaSettings.BitTorrent.Endgame = m_qSettings.value("Endgame", true).toBool();
	quazaaSettings.BitTorrent.ExtraKeys = m_qSettings.value("ExtraKeys", true).toBool();
	quazaaSettings.BitTorrent.LinkPing = m_qSettings.value("LinkPing", 120).toInt();
	quazaaSettings.BitTorrent.LinkTimeout = m_qSettings.value("LinkTimeout", 180).toInt();
	quazaaSettings.BitTorrent.Managed = m_qSettings.value("Managed", true).toBool();
	quazaaSettings.BitTorrent.PreferBTSources = m_qSettings.value("PreferBTSources", true).toBool();
	quazaaSettings.BitTorrent.RandomPeriod = m_qSettings.value("RandomPeriod", 30).toInt();
	quazaaSettings.BitTorrent.RequestLimit = m_qSettings.value("RequestLimit", 128).toInt();
	quazaaSettings.BitTorrent.RequestPipe = m_qSettings.value("RequestPipe", 4).toInt();
	quazaaSettings.BitTorrent.RequestSize = m_qSettings.value("RequestSize", 16).toInt();
	quazaaSettings.BitTorrent.ShowFilesInDownload = m_qSettings.value("ShowFilesInDownload", true).toBool();
	quazaaSettings.BitTorrent.SourceExchangePeriod = m_qSettings.value("SourceExchangePeriod", 10).toInt();
	quazaaSettings.BitTorrent.StartPaused = m_qSettings.value("StartPaused", false).toBool();
	quazaaSettings.BitTorrent.TestPartials = m_qSettings.value("TestPartials", true).toBool();
	quazaaSettings.BitTorrent.TorrentPath = m_qSettings.value("TorrentPath", QDesktopServices::storageLocation(QDesktopServices::HomeLocation) + "/Quazaa/Torrents").toString();
	quazaaSettings.BitTorrent.TrackerKey = m_qSettings.value("TrackerKey", true).toBool();
	quazaaSettings.BitTorrent.UploadCount = m_qSettings.value("UploadCount", 4).toInt();
	quazaaSettings.BitTorrent.UseKademlia = m_qSettings.value("UseKademlia", true).toBool();
	quazaaSettings.BitTorrent.UseSaveDialog = m_qSettings.value("UseSaveDialog", false).toBool();
	quazaaSettings.BitTorrent.UseTemp = m_qSettings.value("UseTemp", false).toBool();
	m_qSettings.endGroup();

	m_qSettings.beginGroup("Discovery");
	quazaaSettings.Discovery.AccessThrottle = m_qSettings.value("AccessThrottle", 60).toInt();
	quazaaSettings.Discovery.BootstrapCount = m_qSettings.value("BootstrapCount", 10).toInt();
	quazaaSettings.Discovery.CacheCount = m_qSettings.value("CacheCount", 50).toInt();
	quazaaSettings.Discovery.DefaultUpdate = m_qSettings.value("DefaultUpdate", 60).toInt();
	quazaaSettings.Discovery.EnableG1GWC = m_qSettings.value("EnableG1GWC", false).toBool();
	quazaaSettings.Discovery.FailureLimit = m_qSettings.value("FailureLimit", 2).toInt();
	quazaaSettings.Discovery.Lowpoint = m_qSettings.value("Lowpoint", 10).toInt();
	quazaaSettings.Discovery.UpdatePeriod = m_qSettings.value("UpdatePeriod", 30).toInt();
	m_qSettings.endGroup();

	m_qSettings.beginGroup("Scheduler");

	m_qSettings.endGroup();
}

void QuazaaSettings::saveProfile()
{
	QSettings m_qSettings( quazaaGlobals.ApplicationOrganizationName(), quazaaGlobals.ApplicationName() );

	m_qSettings.beginGroup("Profile");
	m_qSettings.setValue( "Age", quazaaSettings.Profile.Age );
	m_qSettings.setValue( "AolScreenName", quazaaSettings.Profile.AolScreenName );							// Aol screen name
	m_qSettings.setValue( "AvatarPath", quazaaSettings.Profile.AvatarPath );								// Path to an avatar image file. Quazaa logo used if blank
	m_qSettings.setValue( "Biography", quazaaSettings.Profile.Biography );								// Your life story..
	m_qSettings.setValue( "City", quazaaSettings.Profile.City );									// Your city
	m_qSettings.setValue( "Country", quazaaSettings.Profile.Country );								// Your country..
	m_qSettings.setValue( "Email", quazaaSettings.Profile.Email );									// EMail address
	m_qSettings.setValue( "Favorites", quazaaSettings.Profile.Favorites );								// Favorite websites
	m_qSettings.setValue( "FavoritesURL", quazaaSettings.Profile.FavoritesURL );							// Favorite Websites URLs
	m_qSettings.setValue( "Gender", quazaaSettings.Profile.Gender );									// Gender..
	m_qSettings.setValue( "GnutellaScreenName", quazaaSettings.Profile.GnutellaScreenName );						// The name displayed in searches, uploads and downloads and when users browse your system
	m_qSettings.setValue( "GUID", quazaaSettings.Profile.GUID.toString() );									// Unique ID for each client. Can be regenerated
	m_qSettings.setValue( "ICQuin", quazaaSettings.Profile.ICQuin );									// Identification number in ICQ
	m_qSettings.setValue( "Interests", quazaaSettings.Profile.Interests );								// What do you like to do other than use Quazaa
	m_qSettings.setValue( "IrcAlternateNickname", quazaaSettings.Profile.IrcAlternateNickname );					// Alternate nickname in Irc chat if first one is already used
	m_qSettings.setValue( "IrcNickname", quazaaSettings.Profile.IrcNickname );							// Nickname used in Irc chat
	m_qSettings.setValue( "IrcUserName", quazaaSettings.Profile.IrcUserName );							// User name for Irc chat
	m_qSettings.setValue( "JabberID", quazaaSettings.Profile.JabberID );								// Jabber ID
	m_qSettings.setValue( "Latitude", quazaaSettings.Profile.Latitude );								// Location for a disgruntled P2P user to aim a missile
	m_qSettings.setValue( "Longitude", quazaaSettings.Profile.Longitude );								// Location for a disgruntled P2P user to aim a missile
	m_qSettings.setValue( "MSNPassport", quazaaSettings.Profile.MSNPassport );							// Microsoft's Messenger ID
	m_qSettings.setValue( "MyspaceProfile", quazaaSettings.Profile.MyspaceProfile );							// Myspace profile excluding http://quazaaSettings.Profile.myspace.com/
	m_qSettings.setValue( "RealName", quazaaSettings.Profile.RealName );								// User's real name
	m_qSettings.setValue( "StateProvince", quazaaSettings.Profile.StateProvince );							// Your state or province
	m_qSettings.setValue( "YahooID", quazaaSettings.Profile.YahooID );								// Yahoo Messenger ID
	m_qSettings.endGroup();
}

void QuazaaSettings::loadProfile()
{
	QSettings m_qSettings( quazaaGlobals.ApplicationOrganizationName(), quazaaGlobals.ApplicationName() );

	m_qSettings.beginGroup("Profile");

	quazaaSettings.Profile.Age = m_qSettings.value("Age", 18).toInt();
	quazaaSettings.Profile.AolScreenName = m_qSettings.value("AolScreenName", "").toString();
	quazaaSettings.Profile.AvatarPath = m_qSettings.value("AvatarPath", ":/Resource/Chat/DefaultAvatar.png").toString();
	quazaaSettings.Profile.Biography = m_qSettings.value("Biography", "").toString();
	quazaaSettings.Profile.City = m_qSettings.value("City", "").toString();
	quazaaSettings.Profile.Country = m_qSettings.value("Country", "").toString();
	quazaaSettings.Profile.Email = m_qSettings.value("Email", "").toString();
	quazaaSettings.Profile.Favorites = m_qSettings.value("Favorites", QStringList()).toStringList();
	quazaaSettings.Profile.FavoritesURL = m_qSettings.value("FavoritesURL", QStringList()).toStringList();
	quazaaSettings.Profile.Gender = m_qSettings.value("Gender", 0).toInt();
	quazaaSettings.Profile.GnutellaScreenName = m_qSettings.value("GnutellaScreenName", tr("Quazaa User")).toString();
	quazaaSettings.Profile.GUID = m_qSettings.value("GUID", QUuid::createUuid().toString()).toString();
	quazaaSettings.Profile.ICQuin = m_qSettings.value("ICQuin", "").toString();
	quazaaSettings.Profile.Interests = m_qSettings.value("Interests", QStringList()).toStringList();
	quazaaSettings.Profile.IrcAlternateNickname = m_qSettings.value("IrcAlternateNickname", "").toString();
	quazaaSettings.Profile.IrcNickname = m_qSettings.value("IrcNickname", tr("Quazaa User")).toString();
	quazaaSettings.Profile.IrcUserName = m_qSettings.value("IrcUserName", tr("QuazaaUser")).toString();
	quazaaSettings.Profile.JabberID = m_qSettings.value("JabberID", "").toString();
	quazaaSettings.Profile.Latitude = m_qSettings.value("Latitude", "").toString();
	quazaaSettings.Profile.Longitude = m_qSettings.value("Longitude", "").toString();
	quazaaSettings.Profile.MSNPassport = m_qSettings.value("MSNPassport", "").toString();
	quazaaSettings.Profile.MyspaceProfile = m_qSettings.value("MyspaceProfile", "").toString();
	quazaaSettings.Profile.RealName = m_qSettings.value("RealName", "").toString();
	quazaaSettings.Profile.StateProvince = m_qSettings.value("StateProvince", "").toString();
	quazaaSettings.Profile.YahooID = m_qSettings.value("YahooID", "").toString();
	m_qSettings.endGroup();
}

void QuazaaSettings::saveSkinWindowSettings(QSkinDialog *skinDialog)
{
	QSettings m_qSettings( quazaaGlobals.ApplicationOrganizationName(), quazaaGlobals.ApplicationName() );

	m_qSettings.setValue( "NormalPositionAndSize", skinDialog->dialogNormalGeometry() );
	m_qSettings.setValue( "WindowMinimized", skinDialog->isMinimized() );
	m_qSettings.setValue( "WindowMaximized", skinDialog->isMaximized() );
	m_qSettings.setValue( "WindowVisible", skinDialog->isVisible() );
}

void QuazaaSettings::loadSkinWindowSettings(QSkinDialog *skinDialog)
{
	QSettings m_qSettings( quazaaGlobals.ApplicationOrganizationName(), quazaaGlobals.ApplicationName() );

	skinDialog->setGeometry(m_qSettings.value( "NormalPositionAndSize", QRect( QPoint(200,200), QSize(535,104) ) ).toRect());
	skinDialog->setMaximized(m_qSettings.value("WindowMaximized", false).toBool());
	skinDialog->setMinimized(m_qSettings.value("WindowMinimized", false).toBool());
	quazaaSettings.WinMain.Visible = m_qSettings.value( "WindowVisible", true ).toBool();
}

void QuazaaSettings::saveWindowSettings(QMainWindow *window)
{
	QSettings m_qSettings( quazaaGlobals.ApplicationOrganizationName(), quazaaGlobals.ApplicationName() );

	m_qSettings.setValue( "ActiveTab", quazaaSettings.WinMain.ActiveTab );
	m_qSettings.setValue( "ChatRoomsTaskVisible", quazaaSettings.WinMain.ChatRoomsTaskVisible );
	m_qSettings.setValue( "ChatFriendsTaskVisible", quazaaSettings.WinMain.ChatFriendsTaskVisible );
	m_qSettings.setValue( "ChatToolbars", quazaaSettings.WinMain.ChatToolbars );
	m_qSettings.setValue( "DiscoveryToolbar", quazaaSettings.WinMain.DiscoveryToolbar );
	m_qSettings.setValue( "DownloadsToolbar", quazaaSettings.WinMain.DownloadsToolbar );
	m_qSettings.setValue( "GraphSplitter", quazaaSettings.WinMain.GraphSplitter );
	m_qSettings.setValue( "GraphToolbar", quazaaSettings.WinMain.GraphToolbar );
	m_qSettings.setValue( "HomeConnectionTaskVisible", quazaaSettings.WinMain.HomeConnectionTaskVisible );
	m_qSettings.setValue( "HomeDownloadsTaskVisible", quazaaSettings.WinMain.HomeDownloadsTaskVisible );
	m_qSettings.setValue( "HomeLibraryTaskVisible", quazaaSettings.WinMain.HomeLibraryTaskVisible );
	m_qSettings.setValue( "HomeSearchString", quazaaSettings.WinMain.HomeSearchString );
	m_qSettings.setValue( "HomeSplitter", quazaaSettings.WinMain.HomeSplitter );
	m_qSettings.setValue( "HomeTorrentsTaskVisible", quazaaSettings.WinMain.HomeTorrentsTaskVisible );
	m_qSettings.setValue( "HomeUploadsTaskVisible", quazaaSettings.WinMain.HomeUploadsTaskVisible );
	m_qSettings.setValue( "HostCacheSplitter", quazaaSettings.WinMain.HostCacheSplitter );
	m_qSettings.setValue( "HostCacheToolbar", quazaaSettings.WinMain.HostCacheToolbar );
	m_qSettings.setValue( "LibraryDetailsSplitter", quazaaSettings.WinMain.LibraryDetailsSplitter );
	m_qSettings.setValue( "LibraryDetailsVisible", quazaaSettings.WinMain.LibraryDetailsVisible );
	m_qSettings.setValue( "LibraryNavigatorTab", quazaaSettings.WinMain.LibraryNavigatorTab );
	m_qSettings.setValue( "LibrarySplitter", quazaaSettings.WinMain.LibrarySplitter );
	m_qSettings.setValue( "LibraryToolbar", quazaaSettings.WinMain.LibraryToolbar );
	m_qSettings.setValue( "MainToolbar", quazaaSettings.WinMain.MainToolbar );
	m_qSettings.setValue( "MediaPlaylistVisible", quazaaSettings.WinMain.MediaPlaylistVisible );
	m_qSettings.setValue( "MediaSplitter", quazaaSettings.WinMain.MediaSplitter );
	m_qSettings.setValue( "MediaToolbars", quazaaSettings.WinMain.MediaToolbars );
	m_qSettings.setValue( "NeighborsToolbars", quazaaSettings.WinMain.NeighborsToolbars );
	m_qSettings.setValue( "PacketDumpToolbar", quazaaSettings.WinMain.PacketDumpToolbar );
	m_qSettings.setValue( "ActivitySplitter", quazaaSettings.WinMain.ActivitySplitter );
	m_qSettings.setValue( "SchedulerToolbar", quazaaSettings.WinMain.SchedulerToolbar );
	m_qSettings.setValue( "SearchDetailsSplitter", quazaaSettings.WinMain.SearchDetailsSplitter );
	m_qSettings.setValue( "SearchDetailsVisible", quazaaSettings.WinMain.SearchDetailsVisible );
	m_qSettings.setValue( "SearchFileTypeTaskVisible", quazaaSettings.WinMain.SearchFileTypeTaskVisible );
	m_qSettings.setValue( "SearchMonitorToolbar", quazaaSettings.WinMain.SearchMonitorToolbar );
	m_qSettings.setValue( "SearchNetworksTaskVisible", quazaaSettings.WinMain.SearchNetworksTaskVisible );
	m_qSettings.setValue( "SearchResultsTaskVisible", quazaaSettings.WinMain.SearchResultsTaskVisible );
	m_qSettings.setValue( "SearchSidebarVisible", quazaaSettings.WinMain.SearchSidebarVisible );
	m_qSettings.setValue( "SearchSplitter", quazaaSettings.WinMain.SearchSplitter );
	m_qSettings.setValue( "SearchTaskVisible", quazaaSettings.WinMain.SearchTaskVisible );
	m_qSettings.setValue( "SearchToolbar", quazaaSettings.WinMain.SearchToolbar );
	m_qSettings.setValue( "SecurityToolbars", quazaaSettings.WinMain.SecurityToolbars );
	m_qSettings.setValue( "SystemLogToolbar", quazaaSettings.WinMain.SystemLogToolbar );
	m_qSettings.setValue( "TransfersSplitter", quazaaSettings.WinMain.TransfersSplitter );
	m_qSettings.setValue( "UploadsToolbar", quazaaSettings.WinMain.UploadsToolbar );
}

void QuazaaSettings::loadWindowSettings(QMainWindow *window)
{
	QSettings m_qSettings( quazaaGlobals.ApplicationOrganizationName(), quazaaGlobals.ApplicationName() );

	quazaaSettings.WinMain.ActiveTab = m_qSettings.value( "ActiveTab", 0 ).toInt();
	quazaaSettings.WinMain.ChatRoomsTaskVisible = m_qSettings.value( "ChatRoomsTaskVisible", true ).toBool();
	quazaaSettings.WinMain.ChatFriendsTaskVisible = m_qSettings.value( "ChatFriendsTaskVisible", true ).toBool();
	quazaaSettings.WinMain.ChatToolbars = m_qSettings.value( "ChatToolbars", QByteArray() ).toByteArray();
	quazaaSettings.WinMain.DiscoveryToolbar = m_qSettings.value( "DiscoveryToolbar", QByteArray() ).toByteArray();
	quazaaSettings.WinMain.DownloadsToolbar = m_qSettings.value( "DownloadsToolbar", QByteArray() ).toByteArray();
	quazaaSettings.WinMain.GraphSplitter = m_qSettings.value( "GraphSplitter", QByteArray() ).toByteArray();
	quazaaSettings.WinMain.GraphToolbar = m_qSettings.value( "GraphToolbar", QByteArray() ).toByteArray();
	quazaaSettings.WinMain.HomeLibraryTaskVisible = m_qSettings.value( "HomeLibraryTaskVisible", true ).toBool();
	quazaaSettings.WinMain.HomeDownloadsTaskVisible = m_qSettings.value( "HomeDownloadsTaskVisible", true ).toBool();
	quazaaSettings.WinMain.HomeUploadsTaskVisible = m_qSettings.value( "HomeUploadsTaskVisible", true ).toBool();
	quazaaSettings.WinMain.HomeConnectionTaskVisible = m_qSettings.value( "HomeConnectionTaskVisible", true ).toBool();
	quazaaSettings.WinMain.HomeTorrentsTaskVisible = m_qSettings.value( "HomeTorrentsTaskVisible", true ).toBool();
	quazaaSettings.WinMain.HomeSearchString = m_qSettings.value( "HomeSearchString", "" ).toString();
	quazaaSettings.WinMain.HomeSplitter = m_qSettings.value( "HomeSplitter", QByteArray() ).toByteArray();
	quazaaSettings.WinMain.HostCacheSplitter = m_qSettings.value( "HostCacheSplitter", QByteArray() ).toByteArray();
	quazaaSettings.WinMain.HostCacheToolbar = m_qSettings.value( "HostCacheToolbar", QByteArray() ).toByteArray();
	quazaaSettings.WinMain.LibraryDetailsSplitter = m_qSettings.value( "LibraryDetailsSplitter", QByteArray() ).toByteArray();
	quazaaSettings.WinMain.LibrarySplitter = m_qSettings.value( "LibrarySplitter", QByteArray() ).toByteArray();
	quazaaSettings.WinMain.LibraryNavigatorTab = m_qSettings.value( "LibraryNavigatorTab", 0 ).toInt();
	quazaaSettings.WinMain.LibraryDetailsVisible = m_qSettings.value( "LibraryDetailsVisible", true ).toBool();
	quazaaSettings.WinMain.LibraryToolbar = m_qSettings.value( "LibraryToolbar", QByteArray() ).toByteArray();
	quazaaSettings.WinMain.MainToolbar = m_qSettings.value( "MainToolbar", QByteArray() ).toByteArray();
	quazaaSettings.WinMain.MediaSplitter = m_qSettings.value( "MediaSplitter", QByteArray() ).toByteArray();
	quazaaSettings.WinMain.MediaToolbars = m_qSettings.value( "MediaToolbars", QByteArray() ).toByteArray();
	quazaaSettings.WinMain.NeighborsToolbars = m_qSettings.value( "NeighborsToolbars", QByteArray() ).toByteArray();
	quazaaSettings.WinMain.PacketDumpToolbar = m_qSettings.value( "PacketDumpToolbar", QByteArray() ).toByteArray();
	quazaaSettings.WinMain.ActivitySplitter = m_qSettings.value( "ActivitySplitter", QByteArray() ).toByteArray();
	quazaaSettings.WinMain.SchedulerToolbar = m_qSettings.value( "SchedulerToolbar", QByteArray() ).toByteArray();
	quazaaSettings.WinMain.SearchDetailsSplitter = m_qSettings.value( "SearchDetailsSplitter", QByteArray() ).toByteArray();
	quazaaSettings.WinMain.SearchTaskVisible = m_qSettings.value( "SearchTaskVisible", true ).toBool();
	quazaaSettings.WinMain.SearchNetworksTaskVisible = m_qSettings.value( "SearchNetworksTaskVisible", true ).toBool();
	quazaaSettings.WinMain.SearchFileTypeTaskVisible = m_qSettings.value( "SearchFileTypeTaskVisible", true ).toBool();
	quazaaSettings.WinMain.SearchResultsTaskVisible = m_qSettings.value( "SearchResultsTaskVisible", true ).toBool();
	quazaaSettings.WinMain.SearchMonitorToolbar = m_qSettings.value( "SearchMonitorToolbar", QByteArray() ).toByteArray();
	quazaaSettings.WinMain.MediaPlaylistVisible = m_qSettings.value( "MediaPlaylistVisible", true ).toBool();
	quazaaSettings.WinMain.SearchSplitter = m_qSettings.value( "SearchSplitter", QByteArray() ).toByteArray();
	quazaaSettings.WinMain.SearchSidebarVisible = m_qSettings.value( "SearchSidebarVisible", true ).toBool();
	quazaaSettings.WinMain.SearchDetailsVisible = m_qSettings.value( "SearchDetailsVisible", true ).toBool();
	quazaaSettings.WinMain.SearchToolbar = m_qSettings.value( "SearchToolbar", QByteArray() ).toByteArray();
	quazaaSettings.WinMain.SecurityToolbars = m_qSettings.value( "SecurityToolbars", QByteArray() ).toByteArray();
	quazaaSettings.WinMain.SystemLogToolbar = m_qSettings.value( "SystemLogToolbar", QByteArray() ).toByteArray();
	quazaaSettings.WinMain.TransfersSplitter = m_qSettings.value( "TransfersSplitter", QByteArray() ).toByteArray();
	quazaaSettings.WinMain.UploadsToolbar = m_qSettings.value( "UploadsToolbar", QByteArray() ).toByteArray();
}

void QuazaaSettings::saveLanguageSettings()
{
	QSettings m_qSettings( quazaaGlobals.ApplicationOrganizationName(), quazaaGlobals.ApplicationName() );

	m_qSettings.beginGroup("Language");
	m_qSettings.setValue("LanguageFile", quazaaSettings.Language.File);
	m_qSettings.endGroup();
}

void QuazaaSettings::loadLanguageSettings()
{
	QSettings m_qSettings( quazaaGlobals.ApplicationOrganizationName(), quazaaGlobals.ApplicationName() );

	m_qSettings.beginGroup("Language");
	quazaaSettings.Language.File = m_qSettings.value("LanguageFile", ("quazaa_default_en")).toString();
	m_qSettings.endGroup();
}

void QuazaaSettings::saveFirstRun(bool firstRun)
{
	QSettings m_qSettings( quazaaGlobals.ApplicationOrganizationName(), quazaaGlobals.ApplicationName() );
	m_qSettings.setValue("FirstRun", firstRun);
}

bool QuazaaSettings::FirstRun()
{
	QSettings m_qSettings( quazaaGlobals.ApplicationOrganizationName(), quazaaGlobals.ApplicationName() );
	return m_qSettings.value("FirstRun", true).toBool();
}

void QuazaaSettings::saveSkinSettings()
{
	QSettings m_qSettings( quazaaGlobals.ApplicationOrganizationName(), quazaaGlobals.ApplicationName() );
	m_qSettings.setValue("SkinFile", Skin.File);
}

void QuazaaSettings::loadSkinSettings()
{
	QSettings m_qSettings( quazaaGlobals.ApplicationOrganizationName(), quazaaGlobals.ApplicationName() );
	Skin.File = m_qSettings.value("SkinFile", qApp->applicationDirPath() + "/Skin/Greenery/Greenery.qsk").toString();
}
