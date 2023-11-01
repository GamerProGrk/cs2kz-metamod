#pragma once
#include "common.h"
#include "addresses.h"
#include "module.h"
#include "utils/schema.h"
#include "utils/interfaces.h"
#include "utils/datatypes.h"

typedef void ClientPrintFilter_t(IRecipientFilter &filter, MsgDest msgDest, const char *msgName, const char *param1, const char *param2, const char *param3, const char *param4);
typedef void InitPlayerMovementTraceFilter_t(CTraceFilterPlayerMovementCS &pFilter, CEntityInstance *pHandleEntity, uint64_t interactWith, int collisionGroup);
typedef void TracePlayerBBoxForGround_t (const Vector &start, const Vector &end, const Vector &minsSrc,
	const Vector &maxsSrc, CTraceFilterPlayerMovementCS *filter, trace_t_s2 &pm, float minGroundNormalZ, bool overwriteEndpos, int *pCounter);
typedef void InitGameTrace_t(trace_t_s2 *trace);
typedef IGameEventListener2 *GetLegacyGameEventListener_t(CPlayerSlot slot);
typedef void SnapViewAngles_t(CBasePlayerPawn *pawn, const QAngle &angle);


extern ClientPrintFilter_t *UTIL_ClientPrintFilter;

namespace utils
{
	bool Initialize(ISmmAPI *ismm, char *error, size_t maxlen);
	void Cleanup();

	CGlobalVars *GetServerGlobals();
	void UnlockConVars();
	void UnlockConCommands();

	void SetEntityMoveType(CBaseEntity *entity, MoveType_t movetype);
	void EntityCollisionRulesChanged(CBaseEntity *entity);

	bool IsEntityPawn(CBaseEntity *entity);
	bool IsEntityController(CBaseEntity *entity);
	
	CBasePlayerController *GetController(CBaseEntity *entity);
	CBasePlayerController *GetController(CPlayerSlot slot);

	extern InitPlayerMovementTraceFilter_t *InitPlayerMovementTraceFilter;
	extern TracePlayerBBoxForGround_t *TracePlayerBBoxForGround;
	extern InitGameTrace_t *InitGameTrace;
	extern GetLegacyGameEventListener_t *GetLegacyGameEventListener;
	extern SnapViewAngles_t *SnapViewAngles;

	bool IsButtonDown(CInButtonState *buttons, u64 button, bool onlyDown = false);
	CPlayerSlot GetEntityPlayerSlot(CBaseEntity *entity);

	// Normalize the angle between -180 and 180.
	f32 NormalizeDeg(f32 a);
	// Gets the difference in angle between 2 angles. 
    // c can be PI (for radians) or 180.0 (for degrees);
	f32 GetAngleDifference(const f32 x, const f32 y, const f32 c);
	
	// Print functions
	void PrintConsole(CBaseEntity *entity, const char *format, ...);
	void PrintChat(CBaseEntity *entity, const char *format, ...);
	void PrintCentre(CBaseEntity *entity, const char *format, ...);
	void PrintAlert(CBaseEntity *entity, const char *format, ...);
	void PrintHTMLCentre(CBaseEntity *entity, const char *format, ...); // This one uses HTML formatting.

	void PrintConsoleAll(const char *format, ...);
	void PrintChatAll(const char *format, ...);
	void PrintCentreAll(const char *format, ...);
	void PrintAlertAll(const char *format, ...);
	void PrintHTMLCentreAll(const char *format, ...); // This one uses HTML formatting.

	// Color print
	void CPrintChat(CBaseEntity *entity, const char *format, ...);
	void CPrintChatAll(const char *format, ...);

}
