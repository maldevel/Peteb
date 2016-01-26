/*
	Peteb - Access Windows 8.1 TEB/PEB (x86 process)
	Copyright (C) 2016  @maldevel

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include <Subauth.h>
#include "SystemTypes.h"

PVOID getTEB();
PVOID getPEB();

int main(int argc, char **argv)
{
	PTEB pTeb = getTEB();
	PPEB pPeb = getPEB();
	return ERROR_SUCCESS;
}


PVOID getTEB() {
	PVOID pTeb;
	__asm
	{
		push eax
		mov eax, fs:[0x18]
			mov pTeb, eax
			pop eax
	}
	return pTeb;
}


PVOID getPEB() {
	PVOID pPeb;
	__asm
	{
		push eax
		mov eax, fs:[0x30]
			mov pPeb, eax
			pop eax
	}
	return pPeb;
}
