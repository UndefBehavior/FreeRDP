/**
 * FreeRDP: A Remote Desktop Protocol Implementation
 * Remote Assistance
 *
 * Copyright 2014 Marc-Andre Moreau <marcandre.moreau@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef FREERDP_CLIENT_ASSISTANCE_H
#define FREERDP_CLIENT_ASSISTANCE_H

#include <freerdp/api.h>
#include <freerdp/freerdp.h>

struct rdp_assistance_file
{
	UINT32 Type;

	char* Username;
	char* LHTicket;
	char* RCTicket;
	char* PassStub;
	UINT32 DtStart;
	UINT32 DtLength;
	BOOL LowSpeed;
	BOOL RCTicketEncrypted;

	char* ConnectionString1;
	char* ConnectionString2;

	BYTE* EncryptedPassStub;
	int EncryptedPassStubLength;

	BYTE* EncryptedLHTicket;
	int EncryptedLHTicketLength;

	char* MachineAddress;
	UINT32 MachinePort;
	char* RASessionId;
	char* RASpecificParams;
};
typedef struct rdp_assistance_file rdpAssistanceFile;

#ifdef __cplusplus
extern "C" {
#endif

FREERDP_API int freerdp_client_assistance_parse_file_buffer(rdpAssistanceFile* file, const char* buffer, size_t size);
FREERDP_API int freerdp_client_assistance_parse_file(rdpAssistanceFile* file, const char* name);
FREERDP_API int freerdp_client_assistance_decrypt(rdpAssistanceFile* file, const char* password);

FREERDP_API int freerdp_client_populate_settings_from_assistance_file(rdpAssistanceFile* file, rdpSettings* settings);

FREERDP_API rdpAssistanceFile* freerdp_client_assistance_file_new();
FREERDP_API void freerdp_client_assistance_file_free(rdpAssistanceFile* file);

#ifdef __cplusplus
}
#endif

#endif /* FREERDP_CLIENT_ASSISTANCE_H */

