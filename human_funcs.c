//----- (00103350) --------------------------------------------------------
float *__cdecl F_HitoVertCalcA(int a1, unsigned __int16 *a2)
{
  unsigned __int16 *v2; // ebp
  float *v3; // esi
  __int16 v4; // ax
  float *v5; // ebp
  signed int v6; // esi
  float *v7; // edi
  signed int v8; // edi
  int *v9; // eax
  float *v10; // ST04_4
  float *v11; // ST14_4
  int v13; // [esp+20h] [ebp-3Ch]
  int v14; // [esp+24h] [ebp-38h]
  int v15; // [esp+28h] [ebp-34h]
  int v16; // [esp+2Ch] [ebp-30h]
  char v17; // [esp+30h] [ebp-2Ch]

  v2 = a2;
  v3 = (float *)*((_DWORD *)a2 + 1);
  v4 = *((_WORD *)v3 + 6);
  if ( *a2 )
  {
    v5 = (float *)*((_DWORD *)a2 + 1);
    v6 = 0;
    v7 = (float *)(a1 + 16 * (v4 & 0xFFF));
    do
    {
      D3DXVec4Transform(v7, v5, (float *)g_sh4_matrix);
      ++v6;
      v7 += 4;
      v5 += 4;
    }
    while ( *a2 > v6 );
    v3 = v5;
    v2 = a2;
  }
  if ( v2[1] )
  {
    v8 = 0;
    do
    {
      ++v8;
      v9 = (int *)(a1 + 16 * ((_WORD)v3[3] & 0xFFF));
      v13 = *v9;
      v14 = v9[1];
      v15 = v9[2];
      v16 = v9[3];
      v10 = v3;
      v11 = (float *)v9;
      v3 += 4;
      D3DXVec4Transform((float *)&v17, v10, (float *)g_sh4_matrix);
      D3DXVec4Add(v11, (float *)&v17, (float *)&v13);
    }
    while ( v2[1] > v8 );
  }
  return v3;
}

unsigned int __cdecl VertexBuffer::VertexBuffer(VertexBuffer *this, int a2, int a3, unsigned int a4)
{
  unsigned int result; // eax
  int v5; // ST10_4
  int v6; // ST14_4
  int v7; // ST10_4
  int v8; // ST14_4
  int v9; // ST10_4
  int v10; // ST14_4
  int v11; // [esp+Ch] [ebp-20h]
  int v12; // [esp+10h] [ebp-1Ch]
  int v13; // [esp+14h] [ebp-18h]

  GlResID::GlResID((VertexBuffer *)((char *)this + 32));
  if ( a3 <= 0 || a2 <= 0 )
  {
    __android_log_print(6, "SC", "System halt.", v11, v12, v13);
    __android_log_print(6, "SC", "    FILE:[%s]", "E:/android/workspace2/SoulCalibur10GP/jni/VertexBuffer.cpp", v5, v6);
    __android_log_print(6, "SC", "    LINE:[%d]", 71, v7, v8);
    __android_log_print(6, "SC", "    FUNC:[%s()]", "VertexBuffer", v9, v10);
    exit(1);
  }
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 34962;
  *((_DWORD *)this + 6) = 35044;
  *((_BYTE *)this + 28) = 0;
  GlResID::clear((VertexBuffer *)((char *)this + 32));
  *((_DWORD *)this + 1) = a3;
  *((_DWORD *)this + 3) = a2;
  result = a4;
  *((_DWORD *)this + 5) = a4;
  return result;
}

//----- (000D8440) --------------------------------------------------------
void *__cdecl VertexBuffer::allocateBuffer(VertexBuffer *this, int a2)
{
  int v2; // eax
  void *result; // eax
  int v4; // ST10_4
  int v5; // ST14_4
  int v6; // ST10_4
  int v7; // ST14_4
  int v8; // ST10_4
  int v9; // ST14_4
  int v10; // [esp+Ch] [ebp-10h]
  int v11; // [esp+10h] [ebp-Ch]
  int v12; // [esp+14h] [ebp-8h]

  v2 = *((_DWORD *)this + 3);
  if ( a2 <= 0 || !v2 )
  {
    __android_log_print(6, "SC", "System halt.", v10, v11, v12);
    __android_log_print(6, "SC", "    FILE:[%s]", "E:/android/workspace2/SoulCalibur10GP/jni/VertexBuffer.cpp", v4, v5);
    __android_log_print(6, "SC", "    LINE:[%d]", 86, v6, v7);
    __android_log_print(6, "SC", "    FUNC:[%s()]", "allocateBuffer", v8, v9);
    exit(1);
  }
  if ( *(_DWORD *)this )
  {
    free(*(void **)this);
    v2 = *((_DWORD *)this + 3);
  }
  *((_DWORD *)this + 2) = a2;
  result = malloc(*((_DWORD *)this + 1) * v2 * a2);
  *(_DWORD *)this = result;
  return result;
}

//----- (000D8540) --------------------------------------------------------
int __cdecl VertexBuffer::operator char *(int a1)
{
  return *(_DWORD *)a1;
}

//----- (000D8550) --------------------------------------------------------
VertexBuffer *__cdecl VertexBuffer::resetIndex(VertexBuffer *this)
{
  VertexBuffer *result; // eax

  result = this;
  *((_DWORD *)this + 4) = 0;
  return result;
}

//----- (000D8560) --------------------------------------------------------
int __cdecl VertexBuffer::setIndex(VertexBuffer *this, int a2)
{
  int result; // eax
  int v3; // ST10_4
  int v4; // ST14_4
  int v5; // ST10_4
  int v6; // ST14_4
  int v7; // ST10_4
  int v8; // ST14_4
  int v9; // [esp+Ch] [ebp-10h]
  int v10; // [esp+10h] [ebp-Ch]
  int v11; // [esp+14h] [ebp-8h]

  result = *((_DWORD *)this + 3) * *((_DWORD *)this + 2);
  if ( result <= a2 )
  {
    __android_log_print(6, "SC", "System halt.", v9, v10, v11);
    __android_log_print(6, "SC", "    FILE:[%s]", "E:/android/workspace2/SoulCalibur10GP/jni/VertexBuffer.cpp", v3, v4);
    __android_log_print(6, "SC", "    LINE:[%d]", 119, v5, v6);
    __android_log_print(6, "SC", "    FUNC:[%s()]", "setIndex", v7, v8);
    exit(1);
  }
  *((_DWORD *)this + 4) = a2;
  return result;
}

//----- (000D8630) --------------------------------------------------------
VertexBuffer *__cdecl VertexBuffer::addFloat(VertexBuffer *this, float a2)
{
  VertexBuffer *result; // eax
  int v3; // ecx
  int v4; // ST10_4
  int v5; // ST14_4
  int v6; // ST10_4
  int v7; // ST14_4
  int v8; // ST10_4
  int v9; // ST14_4
  int v10; // [esp+Ch] [ebp-10h]
  int v11; // [esp+10h] [ebp-Ch]
  int v12; // [esp+14h] [ebp-8h]

  result = this;
  v3 = *((_DWORD *)this + 4);
  if ( v3 >= *((_DWORD *)this + 3) * *((_DWORD *)this + 2) || *((_DWORD *)this + 1) != 4 )
  {
    __android_log_print(6, "SC", "System halt.", v10, v11, v12);
    __android_log_print(6, "SC", "    FILE:[%s]", "E:/android/workspace2/SoulCalibur10GP/jni/VertexBuffer.cpp", v4, v5);
    __android_log_print(6, "SC", "    LINE:[%d]", 128, v6, v7);
    __android_log_print(6, "SC", "    FUNC:[%s()]", "addFloat", v8, v9);
    exit(1);
  }
  *(float *)(*(_DWORD *)this + 4 * v3) = a2;
  *((_DWORD *)this + 4) = v3 + 1;
  return result;
}

//----- (000D8720) --------------------------------------------------------
VertexBuffer *__cdecl VertexBuffer::addInt(VertexBuffer *this, int a2)
{
  VertexBuffer *result; // eax
  int v3; // ecx
  int v4; // ST10_4
  int v5; // ST14_4
  int v6; // ST10_4
  int v7; // ST14_4
  int v8; // ST10_4
  int v9; // ST14_4
  int v10; // [esp+Ch] [ebp-10h]
  int v11; // [esp+10h] [ebp-Ch]
  int v12; // [esp+14h] [ebp-8h]

  result = this;
  v3 = *((_DWORD *)this + 4);
  if ( v3 >= *((_DWORD *)this + 3) * *((_DWORD *)this + 2) || *((_DWORD *)this + 1) != 4 )
  {
    __android_log_print(6, "SC", "System halt.", v10, v11, v12);
    __android_log_print(6, "SC", "    FILE:[%s]", "E:/android/workspace2/SoulCalibur10GP/jni/VertexBuffer.cpp", v4, v5);
    __android_log_print(6, "SC", "    LINE:[%d]", 139, v6, v7);
    __android_log_print(6, "SC", "    FUNC:[%s()]", "addInt", v8, v9);
    exit(1);
  }
  *(_DWORD *)(*(_DWORD *)this + 4 * v3) = a2;
  ++*((_DWORD *)this + 4);
  return result;
}

//----- (000D8800) --------------------------------------------------------
VertexBuffer *__cdecl VertexBuffer::addShort(VertexBuffer *this, __int16 a2)
{
  VertexBuffer *result; // eax
  int v3; // ecx
  int v4; // ST10_4
  int v5; // ST14_4
  int v6; // ST10_4
  int v7; // ST14_4
  int v8; // ST10_4
  int v9; // ST14_4
  int v10; // [esp+Ch] [ebp-10h]
  int v11; // [esp+10h] [ebp-Ch]
  int v12; // [esp+14h] [ebp-8h]

  result = this;
  v3 = *((_DWORD *)this + 4);
  if ( v3 >= *((_DWORD *)this + 3) * *((_DWORD *)this + 2) || *((_DWORD *)this + 1) != 2 )
  {
    __android_log_print(6, "SC", "System halt.", v10, v11, v12);
    __android_log_print(6, "SC", "    FILE:[%s]", "E:/android/workspace2/SoulCalibur10GP/jni/VertexBuffer.cpp", v4, v5);
    __android_log_print(6, "SC", "    LINE:[%d]", 150, v6, v7);
    __android_log_print(6, "SC", "    FUNC:[%s()]", "addShort", v8, v9);
    exit(1);
  }
  *(_WORD *)(*(_DWORD *)this + 2 * v3) = a2;
  *((_DWORD *)this + 4) = v3 + 1;
  return result;
}

//----- (000D88F0) --------------------------------------------------------
int __cdecl VertexBuffer::getPointer(VertexBuffer *this, int a2)
{
  int result; // eax

  if ( *((_BYTE *)this + 28) )
    result = *((_DWORD *)this + 1) * a2;
  else
    result = *(_DWORD *)this + *((_DWORD *)this + 1) * a2;
  return result;
}

//----- (000D8910) --------------------------------------------------------
bool __cdecl VertexBuffer::checkID(VertexBuffer *this)
{
  return GlResID::isValid((VertexBuffer *)((char *)this + 32));
}

//----- (000D8940) --------------------------------------------------------
int __cdecl VertexBuffer::toVBO(VertexBuffer *this, unsigned int a2, GlID *a3)
{
  bool v3; // zf
  int v4; // eax
  int result; // eax
  int v6; // ST10_4
  int v7; // ST14_4
  int v8; // ST10_4
  int v9; // ST14_4
  int v10; // ST10_4
  int v11; // ST14_4
  int v12; // [esp+Ch] [ebp-10h]
  int v13; // [esp+10h] [ebp-Ch]
  int v14; // [esp+14h] [ebp-8h]

  v3 = *((_BYTE *)this + 28) == 0;
  *((_DWORD *)this + 6) = a2;
  if ( !v3 )
  {
    __android_log_print(6, "SC", "System halt.", v12, v13, v14);
    __android_log_print(6, "SC", "    FILE:[%s]", "E:/android/workspace2/SoulCalibur10GP/jni/VertexBuffer.cpp", v6, v7);
    __android_log_print(6, "SC", "    LINE:[%d]", 238, v8, v9);
    __android_log_print(6, "SC", "    FUNC:[%s()]", "toVBO", v10, v11);
    exit(1);
  }
  GlID::getID(a3, (int)this + 32);
  v4 = GlResID::operator unsigned int((int)this + 32);
  glBindBuffer(*((_DWORD *)this + 5), v4);
  result = glBufferData(
             *((_DWORD *)this + 5),
             *((_DWORD *)this + 3) * *((_DWORD *)this + 1) * *((_DWORD *)this + 2),
             *(_DWORD *)this,
             *((_DWORD *)this + 6));
  *((_BYTE *)this + 28) = 1;
  return result;
}
// B7D34: using guessed type int __cdecl glBindBuffer(_DWORD, _DWORD);
// B7E44: using guessed type int __cdecl glBufferData(_DWORD, _DWORD, _DWORD, _DWORD);

//----- (000D8A70) --------------------------------------------------------
int __cdecl VertexBuffer::bind(VertexBuffer *this)
{
  int v1; // eax
  GlID *v3; // eax

  if ( !*((_BYTE *)this + 28) )
    return glBindBuffer(*((_DWORD *)this + 5), 0);
  if ( !VertexBuffer::checkID(this) )
  {
    v3 = (GlID *)*((_DWORD *)this + 10);
    *((_BYTE *)this + 28) = 0;
    VertexBuffer::toVBO(this, *((_DWORD *)this + 6), v3);
  }
  v1 = GlResID::operator unsigned int((int)this + 32);
  return glBindBuffer(*((_DWORD *)this + 5), v1);
}
// B7D34: using guessed type int __cdecl glBindBuffer(_DWORD, _DWORD);

//----- (000D8B10) --------------------------------------------------------
void __cdecl VertexBuffer::reentryVBO(VertexBuffer *this)
{
  int v1; // eax
  GlID *v2; // eax

  if ( *((_BYTE *)this + 28) )
  {
    if ( !VertexBuffer::checkID(this) )
    {
      v2 = (GlID *)*((_DWORD *)this + 10);
      *((_BYTE *)this + 28) = 0;
      VertexBuffer::toVBO(this, *((_DWORD *)this + 6), v2);
    }
    v1 = GlResID::operator unsigned int((int)this + 32);
    glBindBuffer(*((_DWORD *)this + 5), v1);
    glBufferData(
      *((_DWORD *)this + 5),
      *((_DWORD *)this + 3) * *((_DWORD *)this + 1) * *((_DWORD *)this + 2),
      *(_DWORD *)this,
      *((_DWORD *)this + 6));
  }
}
// B7D34: using guessed type int __cdecl glBindBuffer(_DWORD, _DWORD);
// B7E44: using guessed type int __cdecl glBufferData(_DWORD, _DWORD, _DWORD, _DWORD);

//----- (000D8BC0) --------------------------------------------------------
VertexBuffer *__cdecl VertexBuffers::allocate(VertexBuffers *this, int a2, int a3, int a4, unsigned int a5)
{
  VertexBuffer *result; // eax
  int v6; // esi
  VertexBuffer *v7; // ST1C_4

  *((_DWORD *)this + 1) = a2;
  result = (VertexBuffer *)operator new[](4 * a2);
  *(_DWORD *)this = result;
  if ( a2 > 0 )
  {
    v6 = 0;
    do
    {
      v7 = (VertexBuffer *)operator new(0x30u);
      VertexBuffer::VertexBuffer(v7, a3, a4, a5);
      result = v7;
      *(_DWORD *)(*(_DWORD *)this + 4 * v6++) = v7;
    }
    while ( v6 != a2 );
  }
  return result;
}

//----- (000D8C50) --------------------------------------------------------
VertexBuffer *__cdecl VertexBuffers::VertexBuffers(VertexBuffers *this, int a2, int a3, unsigned int a4, int a5)
{
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  return VertexBuffers::allocate(this, a5, a2, a3, a4);
}

//----- (000D8CB0) --------------------------------------------------------
void __cdecl VertexBuffers::~VertexBuffers(VertexBuffers *this)
{
  void **v1; // eax

  v1 = *(void ***)this;
  if ( **(_DWORD **)this )
  {
    operator delete(**(void ***)this);
    **(_DWORD **)this = 0;
    v1 = *(void ***)this;
  }
  if ( v1 )
  {
    operator delete[](v1);
    *(_DWORD *)this = 0;
  }
}

//----- (000D8D10) --------------------------------------------------------
void *__cdecl VertexBuffers::allocateBuffer(VertexBuffers *this, int a2)
{
  void *result; // eax
  int v3; // esi
  VertexBuffer *v4; // eax

  result = (void *)*((_DWORD *)this + 1);
  if ( (signed int)result > 0 )
  {
    v3 = 0;
    do
    {
      v4 = *(VertexBuffer **)(*(_DWORD *)this + 4 * v3++);
      result = VertexBuffer::allocateBuffer(v4, a2);
    }
    while ( *((_DWORD *)this + 1) > v3 );
  }
  return result;
}

//----- (000D8D60) --------------------------------------------------------
int __cdecl VertexBuffers::toVBO(VertexBuffers *this, unsigned int a2, GlID *a3)
{
  int v3; // esi
  VertexBuffer *v4; // eax
  int result; // eax

  if ( *((_DWORD *)this + 1) > 0 )
  {
    v3 = 0;
    do
    {
      v4 = *(VertexBuffer **)(*(_DWORD *)this + 4 * v3++);
      result = VertexBuffer::toVBO(v4, a2, a3);
    }
    while ( *((_DWORD *)this + 1) > v3 );
  }
  return result;
}

//----- (000D8DC0) --------------------------------------------------------
int __cdecl VertexBuffers::getBuffer(VertexBuffers *this)
{
  return **(_DWORD **)(*(_DWORD *)this + 4 * *((_DWORD *)this + 3));
}

//----- (000D8DD0) --------------------------------------------------------
int __cdecl VertexBuffers::getStride(VertexBuffers *this)
{
  return *(_DWORD *)(*(_DWORD *)(*(_DWORD *)this + 4 * *((_DWORD *)this + 3)) + 12);
}

//----- (000D8DE0) --------------------------------------------------------
int __cdecl VertexBuffers::getStrideByteSize(VertexBuffers *this)
{
  int v1; // edx

  v1 = *(_DWORD *)(*(_DWORD *)this + 4 * *((_DWORD *)this + 3));
  return *(_DWORD *)(v1 + 12) * *(_DWORD *)(v1 + 4);
}

//----- (000D8E00) --------------------------------------------------------
int __cdecl VertexBuffers::reentryVBO(VertexBuffers *this)
{
  int v1; // eax
  int result; // eax
  __int64 v3; // rtt

  VertexBuffer::reentryVBO(*(VertexBuffer **)(*(_DWORD *)this + 4 * *((_DWORD *)this + 3)));
  v1 = *((_DWORD *)this + 3);
  *((_DWORD *)this + 2) = v1++;
  v3 = v1;
  result = v1 / *((_DWORD *)this + 1);
  *((_DWORD *)this + 3) = v3 % *((signed int *)this + 1);
  return result;
}

//----- (000D8E50) --------------------------------------------------------
int __cdecl VertexBuffers::getPointer(VertexBuffers *this, int a2)
{
  return VertexBuffer::getPointer(*(VertexBuffer **)(*(_DWORD *)this + 4 * *((_DWORD *)this + 2)), a2);
}

//----- (000D8E90) --------------------------------------------------------
int __cdecl VertexBuffers::bind(VertexBuffers *this)
{
  return VertexBuffer::bind(*(VertexBuffer **)(*(_DWORD *)this + 4 * *((_DWORD *)this + 2)));

//----- (001A7F60) --------------------------------------------------------
signed int __cdecl S_ReadHumanModel(SoundEngine *a1, int a2, int a3)
{
  int *v3; // esi
  char *v4; // edi
  int v5; // eax
  int v6; // edx
  int *v7; // eax
  void *v8; // ST30_4
  int *v9; // eax
  char *v10; // ST30_4
  signed __int16 *v11; // ST34_4
  char *v12; // eax
  char *v13; // eax
  unsigned int v15; // eax
  int v16; // edx
  void **v17; // edx
  signed int v18; // eax
  unsigned int v19; // ecx
  int v20; // eax
  int v21; // edx
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // ST10_4
  int *v31; // ST14_4
  int v32; // ST10_4
  int *v33; // ST14_4
  int v34; // ST10_4
  int *v35; // ST14_4
  char *v36; // [esp+Ch] [ebp-60h]
  int v37; // [esp+10h] [ebp-5Ch]
  int *v38; // [esp+14h] [ebp-58h]
  char *v39; // [esp+38h] [ebp-34h]
  char *v40; // [esp+3Ch] [ebp-30h]
  int v41; // [esp+44h] [ebp-28h]
  int v42; // [esp+48h] [ebp-24h]
  char *v43; // [esp+4Ch] [ebp-20h]

  v3 = &Player[8633 * (_DWORD)a1];
  v42 = 1193046;
  if ( System[50] != -1 )
    v42 = a2 | (a3 << 8);
  v40 = (char *)WorkArea[0] + 2498560 * (_DWORD)a1 + 5537792;
  v43 = (char *)WorkArea[0] + 2498560 * (_DWORD)a1 + 5537796;
  v4 = (char *)S_32ByteAlign((int)WorkArea[0]);
  if ( *(_DWORD *)v40 != 1430717078 )
    S_ResetHumanModel((int)v3);
  S_ResetHumanModel((int)v3);
  v5 = v3[5902];
  v6 = v3[5904];
  if ( v5 != 6 )
  {
    if ( v5 != 13 )
    {
      if ( v5 != 2 )
        goto LABEL_8;
      goto LABEL_14;
    }
    if ( !v6 )
      goto LABEL_8;
  }
  if ( v6 == 2 )
    goto LABEL_8;
LABEL_14:
  if ( v3[5895] != 1 )
  {
    v15 = TouchChara_getPants() - 1;
    v16 = 1;
    if ( v15 <= 6 )
      v16 = dword_294E08[v15];
    goto LABEL_17;
  }
  v19 = *(_DWORD *)(v3[5968] + 23608);
  switch ( v5 )
  {
    case 6:
      goto LABEL_26;
    case 13:
      if ( v19 <= 0x14 )
      {
        if ( (1 << v19) & 0x110020 )
        {
          v28 = lrand48();
          v16 = 3;
          v29 = v28 % 2;
          if ( v29 )
            v16 = 4 * (v29 == 1) + 1;
          goto LABEL_17;
        }
        if ( (1 << v19) & 0x1010 )
        {
          v25 = lrand48();
          v16 = 8;
          if ( v25 % 2 )
            v16 = (v25 % 2 == 1) + 1;
          goto LABEL_17;
        }
      }
      break;
    case 2:
      if ( v19 == 3 )
      {
        v26 = lrand48();
        LOBYTE(v19) = 3;
        v27 = v26 % 2;
        v16 = 3;
        if ( !v27 )
          goto LABEL_17;
        if ( v27 != 1 )
        {
          v41 = 0;
          goto LABEL_27;
        }
        v41 = 4;
        goto LABEL_34;
      }
      if ( v19 == 9 )
      {
        v20 = lrand48();
        LOBYTE(v19) = 9;
        v21 = v20 % 3;
        v22 = v20 % 3;
        if ( v22 != 1 )
        {
          if ( v21 != 2 )
          {
            v16 = 6;
            if ( !v22 )
              goto LABEL_17;
            v41 = 0;
            goto LABEL_34;
          }
          v41 = 7;
LABEL_27:
          v16 = v41 + 1;
          goto LABEL_17;
        }
        v41 = 6;
LABEL_34:
        if ( (1 << v19) & 0x110020 )
        {
          v23 = lrand48();
          v16 = 3;
          v24 = v23 % 2;
          if ( v24 )
          {
            LOBYTE(v16) = 5;
            if ( v24 != 1 )
              v16 = v41 + 1;
          }
          goto LABEL_17;
        }
        if ( (1 << v19) & 0x1810 )
        {
          v16 = lrand48() % 7 + 2;
          goto LABEL_17;
        }
        goto LABEL_27;
      }
LABEL_26:
      v41 = 0;
      if ( v19 > 0x14 )
        goto LABEL_27;
      goto LABEL_34;
  }
  v16 = 1;
LABEL_17:
  v17 = (void **)((char *)&unk_3A94E0 + 8 * v16);
  if ( System[38] == 49 )
    v17 = &off_3A94E8;
  v18 = *((signed __int16 *)v17 + 2) >> 4;
  if ( v18 > 255 )
    v18 = 255;
  S_Hsv2Rgb(*(signed __int16 *)v17, *((signed __int16 *)v17 + 1), v18);
  F_SetPantyColor(
    v3[5893],
    (float)(signed int)S_Common[4],
    (float)(signed int)S_Common[5],
    (float)(signed int)S_Common[6]);
LABEL_8:
  v3[5990] = (int)v43;
  v39 = (char *)a1 + 132;
  System[(_DWORD)a1 + 132] = 0;
  if ( O_SongCheck() )
    O_SongPause();
  O_LoadData(3, a3 + 10 * (a2 - 1), 0, v4, 0, &System[(_DWORD)v39]);
  if ( !System[(_DWORD)v39] )
  {
    __android_log_print(6, "SC", "System halt.", v36, v37, v38);
    __android_log_print(6, "SC", "    FILE:[%s]", "E:/android/workspace2/SoulCalibur10GP/jni/soul/shuman.cpp", v30, v31);
    __android_log_print(6, "SC", "    LINE:[%d]", 877, v32, v33);
    __android_log_print(6, "SC", "    FUNC:[%s()]", "S_ReadHumanModel", v34, v35);
    exit(1);
  }
  System[(_DWORD)a1 + 96 + 1] = O_Common[3];
  v7 = (int *)S_GetPacAddr2(v4, 0);
  v8 = F_HitoModelInit((int)a1, v43, v7, 0);
  v9 = (int *)S_GetPacAddr2(v4, 2);
  v10 = F_KageModelInit((int)a1, v8, v9);
  Service_prepareVoice(a1, a2 - 1);
  K_InitMotionBone((int)v3);
  v11 = (signed __int16 *)K_HumanSwayInit((int)v3, v10);
  v12 = S_GetPacAddr2(v4, 3);
  O_TAChrData(v3, v12);
  S_GetPacAddr2(v4, 6);
  O_LcdLoad();
  v13 = S_GetPacAddr2(v4, 5);
  O_BossLoad(v3, (int)v13, v11);
  S_SetWatchDeg(v3, (_WORD *)v3[5944]);
  System[(_DWORD)a1 + 96 + 3] = (char *)v11 - v40;
  *(_DWORD *)v40 = 1430717078;
  v3[5958] = v42;
  v3[5959] = 1;
  return 1;
}
// 3A94E8: using guessed type void *off_3A94E8;

//----- (00110500) --------------------------------------------------------
void *__cdecl F_HitoModelInit(int a1, void *a2, int *a3, int a4)
{
  char *v4; // esi
  unsigned int v5; // edi
  int v6; // eax
  _DWORD *v7; // edx
  int v8; // ecx
  int v9; // eax
  int v10; // edx
  int v11; // edi
  int *v12; // ecx
  int *v13; // eax
  int v14; // edx
  int v15; // esi

  v4 = (char *)&F_Hito + 17884 * a1;
  if ( a4 != 2 )
  {
    v4[408] = 0;
    v5 = ((unsigned int)a2 + 31) & 0xFFFFFFE0;
    *((_WORD *)v4 + 310) = 0;
    *((_WORD *)v4 + 230) = 0;
    *((_WORD *)v4 + 231) = 255;
    *(_DWORD *)v4 = 0;
    *((_DWORD *)v4 + 3) = 0;
    *((_WORD *)v4 + 208) = 0;
    *((_DWORD *)v4 + 139) = 45;
    *((_DWORD *)v4 + 141) = -1107296256;
    *((_DWORD *)v4 + 142) = 0;
    *((_DWORD *)v4 + 143) = 0;
    *((_DWORD *)v4 + 140) = -1;
    v6 = F_DecodeNlz2((char *)a3 + a3[1], (void *)v5);
    *((_WORD *)v4 + 208) = *(_WORD *)((char *)&dword_1C + v5);
    *(_DWORD *)v4 = v5;
    *((_WORD *)v4 + 311) = 6144;
    *((_WORD *)v4 + 312) = -6144;
    *((_WORD *)v4 + 313) = 0;
    *((_DWORD *)v4 + 161) = 1048576000;
    *((_DWORD *)v4 + 162) = 1048576000;
    *((_DWORD *)v4 + 164) = 0;
    *((_DWORD *)v4 + 163) = 0;
    v7 = &F_View[4 * (9 * a1 + 9) + 141];
    a2 = (void *)(v5 + v6);
    *((_DWORD *)v4 + 116) = v7;
    *((_BYTE *)v7 + 131) = -1;
    *((_BYTE *)v7 + 130) = 0;
    *((_DWORD *)v4 + 3) = v5 + 32;
    F_UnitMatrix((_DWORD *)v4 + 166, 1065353216);
    v8 = *(unsigned __int16 *)(v5 + 28);
    *((_DWORD *)v4 + 117) = v4 + 4316;
    *((_DWORD *)v4 + 118) = v4 + 11100;
    *(_DWORD *)(v5 + 24) += v5;
    v9 = v5 + 32;
    if ( v8 )
    {
      v10 = 0;
      do
      {
        *(_DWORD *)(v9 + 4) += v5;
        if ( *(_WORD *)(v9 + 22) )
          *(_DWORD *)(v9 + 8) += v5;
        ++v10;
        v9 += 32;
      }
      while ( v10 < v8 );
    }
  }
  v11 = *(_DWORD *)v4;
  if ( *(_DWORD *)v4 )
  {
    ModelMgr_createHumanModel(a1);
    if ( a4 != 1 && *a3 > 1 && !System[a1 + 81] )
    {
      v12 = (int *)((char *)a3 + a3[2]);
      if ( *(_BYTE *)(v11 + 19) & 1 )
      {
        v13 = v12 + 32736;
        v14 = *((unsigned __int16 *)v4 + 293) | (*((unsigned __int16 *)v4 + 293) << 16);
        v15 = *((unsigned __int16 *)v4 + 292) | (*((unsigned __int16 *)v4 + 292) << 16);
        do
        {
          *v13 = v15;
          v13[1] = v14;
          v13 += 2;
        }
        while ( v13 != v12 + 0x8000 );
      }
      kmLoadTexture((int)&F_View[16 * a1 + 985], v12);
    }
  }
  return a2;
}

//----- (000EA7B0) --------------------------------------------------------
ModelMgr *__cdecl ModelMgr::createHumanModel(ModelMgr *this)
{
  unsigned int v1; // eax
  int v2; // edx
  ModelMgr *v3; // ebp
  int v4; // edi
  BaseModel *v6; // ST1C_4
  ArmsModel *v7; // edi
  ArmsModel *v8; // edi
  ShadowModel *v9; // edi
  ShadowModel *v10; // edi
  int v11; // edi
  int v12; // ST04_4

  v1 = 0;
  while ( 1 )
  {
    if ( *((_BYTE *)this + v1 + 50) )
    {
      if ( v1 <= 5 )
      {
        switch ( v1 )
        {
          case 1u:
            v2 = *((_DWORD *)this + 6);
            break;
          case 2u:
            v2 = *((_DWORD *)this + 7);
            break;
          case 3u:
            v2 = *((_DWORD *)this + 8);
            break;
          case 4u:
            v2 = *((_DWORD *)this + 9);
            break;
          case 5u:
            v2 = *((_DWORD *)this + 10);
            break;
          default:
            goto LABEL_4;
        }
      }
      else
      {
LABEL_4:
        v2 = *((_DWORD *)this + 5);
      }
      if ( v2 )
        break;
    }
    if ( ++v1 == 6 )
      goto LABEL_7;
  }
  v11 = 0;
  ModelMgr::disposeHuman(this);
  do
  {
    v12 = v11++;
    ModelMgr::setCreateFlag(this, v12);
  }
  while ( v11 != 6 );
LABEL_7:
  v3 = this;
  v4 = 0;
  do
  {
    if ( *((_BYTE *)v3 + 50) )
    {
      v6 = (BaseModel *)operator new(0x214u);
      Human3Model::Human3Model(v6);
      *((_DWORD *)this + v4 + 5) = v6;
      Human3Model::createModel(v6, (int)&F_Hito + 17884 * v4);
      *((_BYTE *)v3 + 48) = 1;
    }
    ++v4;
    v3 = (ModelMgr *)((char *)v3 + 1);
  }
  while ( v4 != 2 );
  if ( *((_BYTE *)this + 54) )
  {
    v10 = (ShadowModel *)operator new(0x214u);
    ShadowModel::ShadowModel(v10);
    *((_DWORD *)this + 9) = v10;
    ShadowModel::createModel(v10, (int)&F_Hito);
  }
  if ( *((_BYTE *)this + 55) )
  {
    v9 = (ShadowModel *)operator new(0x214u);
    ShadowModel::ShadowModel(v9);
    *((_DWORD *)this + 10) = v9;
    ShadowModel::createModel(v9, (int)&F_Hito + 17884);
  }
  if ( *((_BYTE *)this + 52) )
  {
    v8 = (ArmsModel *)operator new(0x214u);
    ArmsModel::ArmsModel(v8);
    *((_DWORD *)this + 7) = v8;
    ArmsModel::createModel(v8, (int)&F_Hito);
  }
  if ( *((_BYTE *)this + 53) )
  {
    v7 = (ArmsModel *)operator new(0x214u);
    ArmsModel::ArmsModel(v7);
    *((_DWORD *)this + 8) = v7;
    ArmsModel::createModel(v7, (int)&F_Hito + 17884);
  }
  return ModelMgr::clearCreateFlag(this);
}

//----- (000ECE60) --------------------------------------------------------
BaseModel *__cdecl Human3Model::Human3Model(Human3Model *this)
{
  BaseModel *result; // eax

  result = BaseModel::BaseModel(this);
  *((_DWORD *)this + 131) = 0;
  *((_DWORD *)this + 132) = 0;
  return result;
}

//----- (000ECEB0) --------------------------------------------------------
void __cdecl Human3Model::~Human3Model(Human3Model *this)
{
  void *v1; // edi

  v1 = (void *)*((_DWORD *)this + 132);
  if ( v1 )
  {
    VertexBuffers::~VertexBuffers(*((VertexBuffers **)this + 132));
    operator delete(v1);
    *((_DWORD *)this + 132) = 0;
  }
  BaseModel::~BaseModel(this);
}

//----- (000ECF10) --------------------------------------------------------
int __cdecl Human3Model::createModel(BaseModel *a1, int a2)
{
  int v2; // eax
  int v3; // ebp
  int v4; // eax
  unsigned int v5; // edx
  int v6; // eax
  int v7; // ebp
  VertexBuffers *v8; // edi
  int v10; // ST10_4
  int v11; // ST14_4
  int v12; // ST10_4
  int v13; // ST14_4
  int v14; // ST10_4
  int v15; // ST14_4
  unsigned int v16; // [esp+Ch] [ebp-50h]
  int v17; // [esp+10h] [ebp-4Ch]
  int v18; // [esp+14h] [ebp-48h]
  char v19; // [esp+3Fh] [ebp-1Dh]

  v2 = *(_DWORD *)a2;
  *((_DWORD *)a1 + 131) = a2;
  v3 = *(_DWORD *)(v2 + 24);
  BaseModel::allocateVertexInfo(a1, 4000);
  v4 = BaseModel::countTriangle((int)a1, v3);
  if ( v4 <= 0 )
  {
    __android_log_print(6, "SC", "System halt.", v16, v17, v18);
    __android_log_print(6, "SC", "    FILE:[%s]", "E:/android/workspace2/SoulCalibur10GP/jni/Human3Model.cpp", v10, v11);
    __android_log_print(6, "SC", "    LINE:[%d]", 100, v12, v13);
    __android_log_print(6, "SC", "    FUNC:[%s()]", "createModel", v14, v15);
    exit(1);
  }
  BaseModel::allocateTriangleBuffer(a1, v4);
  BaseModel::simpleModelCreate(a1, v3);
  BaseModel::resetMaterialList(a1);
  while ( 1 )
  {
    v6 = BaseModel::getMaterial(a1, &v19);
    if ( v6 <= 0 )
      break;
    v7 = v19 & 0x30;
    v5 = *(_DWORD *)(a2 + 204) + ((v19 & 3) << 14);
    switch ( v7 )
    {
      case 32:
        v5 |= 0x10000000u;
        break;
      case 48:
        v5 |= 0x18000000u;
        break;
      case 16:
        v5 |= 0x8000000u;
        break;
    }
    BaseModel::registTexMaterial(a1, v6, (void *)(*(_DWORD *)(a2 + 200) & 0x327FFC0 | 0x40002D), v5, v19);
  }
  v8 = (VertexBuffers *)operator new(0x10u);
  VertexBuffers::VertexBuffers(v8, 9, 4, 0x8892u, 2);
  *((_DWORD *)a1 + 132) = v8;
  VertexBuffers::allocateBuffer(v8, *((_DWORD *)a1 + 7));
  VertexBuffers::toVBO(*((VertexBuffers **)a1 + 132), 0x88E0u, (GlID *)((char *)&n + 1));
  return VertexBuffer::toVBO(*((VertexBuffer **)a1 + 4), 0x88E4u, (GlID *)((char *)&n + 1));
}

//----- (000ED150) --------------------------------------------------------
int __cdecl Human3Model::getVertexCount(int a1, int a2)
{
  int result; // eax
  unsigned __int16 v3; // si
  unsigned __int16 *v4; // edx
  int v5; // esi
  signed int v6; // ecx

  result = 0;
  v3 = *(_WORD *)(a2 + 28);
  if ( v3 )
  {
    v4 = (unsigned __int16 *)(a2 + 32);
    v5 = v3 + 1;
    v6 = 1;
    do
    {
      if ( v4[6] )
        result += *v4;
      ++v6;
      v4 += 16;
    }
    while ( v6 != v5 );
  }
  return result;
}

//----- (000ED190) --------------------------------------------------------
int __cdecl Human3Model::getNormalCount(int a1, int a2)
{
  int result; // eax
  unsigned __int16 v3; // cx
  int v4; // edx
  signed int v5; // ecx
  unsigned __int16 v6; // si
  unsigned __int16 v7; // di
  int v8; // esi
  int v9; // esi
  int v10; // edi
  int v11; // [esp+0h] [ebp-10h]

  result = 0;
  v3 = *(_WORD *)(a2 + 28);
  if ( v3 )
  {
    v4 = a2 + 32;
    v11 = v3 + 1;
    v5 = 1;
    do
    {
      v6 = *(_WORD *)(v4 + 12);
      if ( v6 )
      {
        v7 = *(_WORD *)(v4 + 14);
        if ( v7 )
        {
          v8 = 16 * v6 + *(_DWORD *)(v4 + 4);
          if ( *(_WORD *)(v8 + 12) >= 0 )
          {
            v9 = v8 + 28;
            v10 = result + v7;
            do
            {
              if ( ++result == v10 )
                break;
              v9 += 16;
            }
            while ( *(_WORD *)(v9 - 16) >= 0 );
          }
        }
      }
      v4 += 32;
      ++v5;
    }
    while ( v5 != v11 );
  }
  return result;
}

//----- (000ED210) --------------------------------------------------------
int __cdecl Human3Model::preparePaintMetal(Human3Model *this)
{
  int v1; // esi
  int v2; // eax
  int v3; // edi
  _DWORD *v4; // ecx
  int v5; // esi
  float *v6; // edx
  float v7; // xmm1_4
  float v8; // xmm0_4
  int v9; // esi
  int result; // eax
  int v11; // [esp-Ch] [ebp-18h]
  int v12; // [esp-8h] [ebp-14h]
  int v13; // [esp-4h] [ebp-10h]

  F_LenzHitoVertNormCalc(
    **((unsigned __int16 ***)this + 131),
    (int *)(*(_DWORD *)(*((_DWORD *)this + 131) + 468) + 128),
    (float *)(*((_DWORD *)this + 131) + 564));
  v1 = VertexBuffers::getBuffer(*((VertexBuffers **)this + 132));
  VertexBuffers::getStride(*((VertexBuffers **)this + 132));
  v12 = F_View[19];
  v11 = F_View[20];
  v13 = *((_DWORD *)this + 7);
  if ( *((_DWORD *)this + 7) > 0 )
  {
    v2 = v1;
    v3 = 0;
    v4 = (_DWORD *)*((_DWORD *)this + 5);
    do
    {
      v5 = v4[1];
      v6 = (float *)(v12 + 16 * *v4);
      *(float *)v2 = *v6;
      ++v3;
      v4 += 5;
      *(float *)(v2 + 4) = v6[1];
      *(float *)(v2 + 8) = v6[2];
      v7 = 640.0 / COERCE_FLOAT(*((_DWORD *)v6 + 2) ^ 0x80000000);
      v8 = v6[1];
      v9 = v11 + 16 * v5;
      *(float *)(v2 + 12) = (float)((float)((float)(v7 * *v6) + 320.0) / 640.0) - *(float *)v9;
      *(float *)(v2 + 16) = (float)((float)((float)(v8 * v7) + 240.0) / 480.0) - *(float *)(v9 + 4);
      *(_DWORD *)(v2 + 20) = *(_DWORD *)v9;
      *(_DWORD *)(v2 + 24) = *(_DWORD *)(v9 + 4);
      *(_DWORD *)(v2 + 28) = *(_DWORD *)(v9 + 8);
      *(_DWORD *)(v2 + 32) = 1065353216;
      v2 += 36;
    }
    while ( v3 != v13 );
  }
  result = VertexBuffers::reentryVBO(*((VertexBuffers **)this + 132));
  *((_BYTE *)this + 4) = 1;
  return result;
}
// 27A51C: using guessed type int dword_27A51C;

//----- (000ED390) --------------------------------------------------------
float *__cdecl Human3Model::calcColor(int a1, int a2, unsigned __int16 a3, int *a4)
{
  int v4; // esi
  unsigned int v5; // edx
  unsigned int v6; // eax
  float v7; // xmm2_4
  float v8; // xmm0_4
  signed int v9; // edx
  float *result; // eax
  signed int v11; // ebp
  float v12; // xmm1_4
  float v13; // xmm4_4
  float v14; // xmm3_4
  float v15; // xmm1_4
  float v16; // xmm3_4
  float v17; // xmm2_4
  float v18; // [esp+30h] [ebp-7Ch]
  float v19; // [esp+34h] [ebp-78h]
  float v20; // [esp+38h] [ebp-74h]
  int v21; // [esp+3Ch] [ebp-70h]
  float v22; // [esp+40h] [ebp-6Ch]
  float v23; // [esp+44h] [ebp-68h]
  float v24; // [esp+48h] [ebp-64h]
  int v25; // [esp+50h] [ebp-5Ch]
  int v26; // [esp+54h] [ebp-58h]
  int v27; // [esp+58h] [ebp-54h]
  int v28; // [esp+5Ch] [ebp-50h]
  int v29; // [esp+60h] [ebp-4Ch]
  int v30; // [esp+64h] [ebp-48h]
  int v31; // [esp+68h] [ebp-44h]
  int v32; // [esp+6Ch] [ebp-40h]
  int v33; // [esp+70h] [ebp-3Ch]
  int v34; // [esp+74h] [ebp-38h]
  int v35; // [esp+78h] [ebp-34h]
  int v36; // [esp+7Ch] [ebp-30h]
  int v37; // [esp+80h] [ebp-2Ch]
  int v38; // [esp+84h] [ebp-28h]
  int v39; // [esp+88h] [ebp-24h]
  int v40; // [esp+8Ch] [ebp-20h]

  v4 = a2;
  v21 = 0;
  v25 = *a4;
  v26 = a4[1];
  v27 = a4[2];
  v29 = a4[4];
  v30 = a4[5];
  v31 = a4[6];
  v33 = a4[8];
  v34 = a4[9];
  v35 = a4[10];
  v37 = a4[12];
  v38 = a4[13];
  v39 = a4[14];
  v18 = (float)((float)((unsigned int)a4[17] >> 16) * 65536.0) + (float)(unsigned __int16)a4[17];
  v5 = a4[18];
  v6 = a4[19];
  v40 = 0;
  v7 = (float)(unsigned __int16)v5;
  v8 = (float)(v5 >> 16) * 65536.0;
  v9 = (unsigned __int16)v6;
  result = (float *)(v6 >> 16);
  v36 = 0;
  v32 = 0;
  v28 = 0;
  v19 = v8 + v7;
  v20 = (float)((float)(signed int)result * 65536.0) + (float)v9;
  if ( a3 )
  {
    v11 = 0;
    do
    {
      D3DXVec4Transform(&v22, (float *)v4, (float *)&v25);
      result = D3DXVec4Add(&v22, &v22, &v18);
      if ( v22 <= 255.0 )
      {
        v12 = v23;
        v13 = v22 / 255.0;
        if ( v23 <= 255.0 )
          goto LABEL_4;
      }
      else
      {
        v12 = v23;
        v22 = 255.0;
        v13 = 1.0;
        if ( v23 <= 255.0 )
        {
LABEL_4:
          v14 = v12;
          v15 = v24;
          v16 = v14 / 255.0;
          if ( v24 > 255.0 )
            goto LABEL_10;
          goto LABEL_5;
        }
      }
      v15 = v24;
      v23 = 255.0;
      v16 = 1.0;
      if ( v24 > 255.0 )
      {
LABEL_10:
        v24 = 255.0;
        v17 = 1.0;
        goto LABEL_6;
      }
LABEL_5:
      v17 = v15 / 255.0;
LABEL_6:
      *(float *)v4 = v13;
      *(_DWORD *)(v4 + 12) = 1065353216;
      *(float *)(v4 + 4) = v16;
      ++v11;
      *(float *)(v4 + 8) = v17;
      v4 += 16;
    }
    while ( v11 < a3 );
  }
  return result;
}

//----- (000ED5D0) --------------------------------------------------------
int __cdecl Human3Model::preparePaint(Human3Model *this)
{
  int *v1; // eax
  int v2; // edx
  int v3; // edi
  int v4; // esi
  __int16 v5; // ax
  int v6; // edx
  signed int v7; // ebp
  __m128 v8; // xmm1
  __m128 v9; // xmm1
  __m128 v10; // xmm3
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  int v13; // eax
  __int16 v14; // di
  float *v15; // edi
  __m128 v16; // xmm1
  __m128 v17; // xmm1
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  float v20; // xmm2_4
  float v21; // xmm2_4
  float v22; // xmm1_4
  int v23; // esi
  _DWORD *v24; // eax
  int v25; // edi
  _DWORD *v26; // edx
  _DWORD *v27; // esi
  _DWORD *v28; // ecx
  int result; // eax
  unsigned __int16 *v30; // [esp+24h] [ebp-C8h]
  int v31; // [esp+24h] [ebp-C8h]
  int v32; // [esp+28h] [ebp-C4h]
  int v33; // [esp+2Ch] [ebp-C0h]
  int v34; // [esp+2Ch] [ebp-C0h]
  signed int v35; // [esp+30h] [ebp-BCh]
  int v36; // [esp+34h] [ebp-B8h]
  unsigned __int16 *v37; // [esp+38h] [ebp-B4h]
  int v38; // [esp+3Ch] [ebp-B0h]
  float v39; // [esp+40h] [ebp-ACh]
  float v40; // [esp+44h] [ebp-A8h]
  float v41; // [esp+48h] [ebp-A4h]
  float v42; // [esp+4Ch] [ebp-A0h]
  int v43; // [esp+50h] [ebp-9Ch]
  int v44; // [esp+54h] [ebp-98h]
  int v45; // [esp+58h] [ebp-94h]
  int v46; // [esp+5Ch] [ebp-90h]
  int v47; // [esp+60h] [ebp-8Ch]
  int v48; // [esp+64h] [ebp-88h]
  int v49; // [esp+68h] [ebp-84h]
  int v50; // [esp+6Ch] [ebp-80h]
  int v51; // [esp+70h] [ebp-7Ch]
  int v52; // [esp+74h] [ebp-78h]
  int v53; // [esp+78h] [ebp-74h]
  int v54; // [esp+7Ch] [ebp-70h]
  int v55; // [esp+80h] [ebp-6Ch]
  int v56; // [esp+84h] [ebp-68h]
  int v57; // [esp+88h] [ebp-64h]
  int v58; // [esp+8Ch] [ebp-60h]
  char v59; // [esp+90h] [ebp-5Ch]
  char v60; // [esp+A0h] [ebp-4Ch]
  char v61; // [esp+B0h] [ebp-3Ch]
  int v62; // [esp+C0h] [ebp-2Ch]
  int v63; // [esp+C4h] [ebp-28h]
  int v64; // [esp+C8h] [ebp-24h]
  int v65; // [esp+CCh] [ebp-20h]

  v38 = *((_DWORD *)this + 131);
  v37 = *(unsigned __int16 **)v38;
  if ( *(_BYTE *)(v38 + 408) == 2 )
    return Human3Model::preparePaintMetal(this);
  v30 = v37 + 16;
  v36 = *(_DWORD *)(v38 + 468) + 128;
  v1 = *(int **)(v38 + 464);
  v43 = *v1;
  v44 = v1[1];
  v45 = v1[2];
  v46 = v1[3];
  v47 = v1[4];
  v48 = v1[5];
  v49 = v1[6];
  v50 = v1[7];
  v51 = v1[8];
  v52 = v1[9];
  v53 = v1[10];
  v54 = v1[11];
  v55 = v1[12];
  v2 = v1[13];
  v58 = 0;
  v57 = 0;
  v56 = 0;
  v55 = 0;
  BaseModel::HitoVertCalcA((int)this, v37[14], v37 + 16, (int *)v36);
  if ( v37[14] )
  {
    v35 = 0;
    do
    {
      if ( v30[6] )
      {
        v3 = *((_DWORD *)v30 + 1) + 16 * (*v30 + v30[1]);
        v4 = *((_DWORD *)v30 + 1) + 16 * (*v30 + v30[1]);
        D3DXVec4Transform((float *)&v59, (float *)v36, (float *)&v43);
        D3DXVec4Transform((float *)&v60, (float *)(v36 + 16), (float *)&v43);
        D3DXVec4Transform((float *)&v61, (float *)(v36 + 32), (float *)&v43);
        v65 = 0;
        v64 = 0;
        v63 = 0;
        v62 = 0;
        v5 = *(_WORD *)(v3 + 12);
        v6 = F_View[20];
        if ( v30[7] )
        {
          if ( v5 < 0 )
          {
            v7 = 0;
            v14 = *(_WORD *)(v3 + 12);
            while ( 1 )
            {
LABEL_15:
              v15 = (float *)(v6 + 16 * (v14 & 0xFFF));
              D3DXVec4Transform(&v39, (float *)v4, (float *)&v59);
              v16.m128_f32[0] = v39;
              v17 = _mm_cmpge_ss(v16, 0);
              LODWORD(v39) = *(unsigned __int128 *)&_mm_andnot_ps(v17, (__m128)0LL) | LODWORD(v39) & v17.m128_i32[0];
              v17.m128_f32[0] = v40;
              v18 = _mm_cmpge_ss(v17, 0);
              LODWORD(v40) = *(unsigned __int128 *)&_mm_andnot_ps(v18, (__m128)0LL) | LODWORD(v40) & v18.m128_i32[0];
              v19.m128_f32[0] = v41;
              v18.m128_i32[0] = LODWORD(v41) & *(unsigned __int128 *)&_mm_cmpge_ss(v19, 0);
              v20 = v42;
              v41 = v18.m128_f32[0];
              if ( v42 < 0.0 )
              {
                v42 = 0.0;
                v20 = 0.0;
              }
              v21 = v20 + v15[3];
              ++v7;
              *v15 = *v15 + v39;
              v22 = v15[1] + v40;
              v15[3] = v21;
              v15[1] = v22;
              v15[2] = v15[2] + v41;
              *(_BYTE *)v15 = *(_BYTE *)(v4 + 8);
              if ( v30[7] <= v7 )
                break;
              v4 += 16;
              v14 = *(_WORD *)(v4 + 12);
              v6 = F_View[20];
            }
          }
          else
          {
            v7 = 0;
            v33 = v6 + 16 * (v5 & 0xFFF);
            while ( 1 )
            {
              D3DXVec4Transform(&v39, (float *)v4, (float *)&v59);
              v8.m128_f32[0] = v39;
              v9 = _mm_cmpge_ss(v8, 0);
              v10 = v9;
              LODWORD(v39) &= v9.m128_i32[0];
              v9.m128_f32[0] = v40;
              v11 = _mm_cmpge_ss(v9, 0);
              LODWORD(v40) = *(unsigned __int128 *)&_mm_andnot_ps(v11, _mm_andnot_ps(v10, (__m128)0LL)) | LODWORD(v40) & v11.m128_i32[0];
              v12.m128_f32[0] = v41;
              LODWORD(v41) &= *(_OWORD *)&_mm_cmpge_ss(v12, 0);
              if ( v42 < 0.0 )
                v42 = 0.0;
              v13 = v33 - v3;
              ++v7;
              *(float *)(v13 + v4) = v39;
              *(float *)(v13 + v4 + 4) = v40;
              *(float *)(v13 + v4 + 8) = v41;
              *(float *)(v13 + v4 + 12) = v42;
              *(_BYTE *)(v13 + v4) = *(_BYTE *)(v4 + 8);
              if ( v30[7] <= v7 )
                break;
              v4 += 16;
              if ( *(_WORD *)(v4 + 12) < 0 )
              {
                v14 = *(_WORD *)(v4 + 12);
                v6 = F_View[20];
                goto LABEL_15;
              }
            }
          }
        }
      }
      ++v35;
      v30 += 16;
      v36 += 64;
    }
    while ( v37[14] > v35 );
  }
  Human3Model::calcColor((int)this, F_View[20], v37[11], (int *)(*(_DWORD *)(v38 + 464) + 64));
  v23 = VertexBuffers::getBuffer(*((VertexBuffers **)this + 132));
  VertexBuffers::getStride(*((VertexBuffers **)this + 132));
  v32 = F_View[19];
  v34 = F_View[20];
  v31 = *((_DWORD *)this + 7);
  if ( *((_DWORD *)this + 7) > 0 )
  {
    v24 = (_DWORD *)v23;
    v25 = 0;
    v26 = (_DWORD *)*((_DWORD *)this + 5);
    do
    {
      v27 = (_DWORD *)(v32 + 16 * *v26);
      v28 = (_DWORD *)(v34 + 16 * v26[1]);
      ++v25;
      *v24 = *v27;
      v24[1] = v27[1];
      v24[2] = v27[2];
      v24[3] = v26[2];
      v24[4] = v26[3];
      v24[5] = *v28;
      v24[6] = v28[1];
      v24[7] = v28[2];
      v24[8] = 1065353216;
      v26 += 5;
      v24 += 9;
    }
    while ( v25 != v31 );
  }
  BaseModel::uvAnimation(
    this,
    *(VertexBuffer **)(**((_DWORD **)this + 132) + 4 * *(_DWORD *)(*((_DWORD *)this + 132) + 12)),
    (float *)(v38 + 604));
  result = VertexBuffers::reentryVBO(*((VertexBuffers **)this + 132));
  *((_BYTE *)this + 4) = 1;
  return result;
}

//----- (000EDB90) --------------------------------------------------------
void __cdecl Human3Model::paint(Human3Model *this)
{
  Human3Model *v1; // esi
  int v2; // edi
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // esi
  int v9; // ebp
  Human3Model *v10; // edx
  Human3Model *v11; // ST2C_4
  const GLvoid *indices; // eax
  _DWORD *v13; // eax
  Human3Model *v14; // eax
  int v15; // ecx
  int v16; // edi
  int v17; // esi
  int v18; // ebp
  BaseModel *v19; // edx
  BaseModel *v20; // ST2C_4
  const GLvoid *v21; // eax
  _DWORD *v22; // eax
  Human3Model *v23; // eax
  int v24; // ecx
  int v25; // edi
  int v26; // esi
  int v27; // ebp
  BaseModel *v28; // edx
  BaseModel *v29; // ST2C_4
  const GLvoid *v30; // eax
  _DWORD *v31; // eax
  char v32; // [esp+30h] [ebp-5Ch]

  v1 = this;
  if ( *((_DWORD *)this + 132) && *((_DWORD *)this + 4) && *(_BYTE *)(*((_DWORD *)this + 131) + 408) )
  {
    Human3Model::preparePaint(this);
    Gl2::enableAttribute((int)Gl2::gl2, 3u);
    v2 = VertexBuffers::getStrideByteSize(*((VertexBuffers **)this + 132));
    VertexBuffers::bind(*((VertexBuffers **)this + 132));
    v3 = VertexBuffers::getPointer(*((VertexBuffers **)this + 132), 0);
    glVertexAttribPointer(0, 3, 5126, 0, v2, v3);
    v4 = VertexBuffers::getPointer(*((VertexBuffers **)this + 132), 3);
    glVertexAttribPointer(1, 2, 5126, 0, v2, v4);
    v5 = VertexBuffers::getPointer(*((VertexBuffers **)this + 132), 5);
    glVertexAttribPointer(3, 4, 5126, 0, v2, v5);
    VertexBuffer::bind(*((VertexBuffer **)this + 4));
    if ( *(_BYTE *)(*((_DWORD *)this + 131) + 408) == 2 )
      Gl2::bind((Gl2 *)Gl2::gl2, 0);
    else
      Gl2::bind((Gl2 *)Gl2::gl2, 2);
    NrMatrix::NrMatrix((NrMatrix *)&v32);
    Gl2::setModelMatrix((Gl2 *)Gl2::gl2, (NrMatrix *)&v32);
    GlStat::setSwitch((GlStat *)&GlStat::glStat, 6, 0);
    if ( *((_DWORD *)this + 10) > 0 )
    {
      v6 = *((_DWORD *)this + 8);
      v7 = 0;
      v8 = 0;
      v9 = 0;
      v10 = this;
      do
      {
        while ( *(_BYTE *)(v6 + v7 + 12) & 0x40 )
        {
          v8 += *(_DWORD *)(v6 + v7);
          ++v9;
          v7 += 20;
          if ( *((_DWORD *)v10 + 10) <= v9 )
            goto LABEL_12;
        }
        v11 = v10;
        ++v9;
        BaseModel::bindTexture(v10, v6 + v7);
        indices = (const GLvoid *)VertexBuffer::getPointer(*((VertexBuffer **)v11 + 4), 3 * v8);
        glDrawElements(4u, 3 * *(_DWORD *)(*((_DWORD *)v11 + 8) + v7), 0x1403u, indices);
        v10 = v11;
        v6 = *((_DWORD *)v11 + 8);
        v13 = (_DWORD *)(v6 + v7);
        v7 += 20;
        v8 += *v13;
      }
      while ( *((_DWORD *)v11 + 10) > v9 );
LABEL_12:
      v1 = v10;
    }
    Gl2::bind((Gl2 *)Gl2::gl2, 8);
    GlStat::cullFace((GlStat *)&GlStat::glStat, 0);
    if ( *((_DWORD *)v1 + 10) > 0 )
    {
      v14 = v1;
      v15 = *((_DWORD *)v1 + 8);
      v16 = 0;
      v17 = 0;
      v18 = 0;
      v19 = v14;
      do
      {
        while ( !(*(_BYTE *)(v15 + v16 + 12) & 0x40) )
        {
          v17 += *(_DWORD *)(v15 + v16);
          ++v18;
          v16 += 20;
          if ( *((_DWORD *)v19 + 10) <= v18 )
            goto LABEL_18;
        }
        v20 = v19;
        ++v18;
        BaseModel::bindTexture(v19, v15 + v16);
        v21 = (const GLvoid *)VertexBuffer::getPointer(*((VertexBuffer **)v20 + 4), 3 * v17);
        glDrawElements(4u, 3 * *(_DWORD *)(*((_DWORD *)v20 + 8) + v16), 0x1403u, v21);
        v19 = v20;
        v15 = *((_DWORD *)v20 + 8);
        v22 = (_DWORD *)(v15 + v16);
        v16 += 20;
        v17 += *v22;
      }
      while ( *((_DWORD *)v20 + 10) > v18 );
LABEL_18:
      v1 = v19;
    }
    GlStat::setSwitch((GlStat *)&GlStat::glStat, 6, 1);
    Gl2::bind((Gl2 *)Gl2::gl2, 9);
    glDepthMask(0);
    if ( *((_DWORD *)v1 + 10) > 0 )
    {
      v23 = v1;
      v24 = *((_DWORD *)v1 + 8);
      v25 = 0;
      v26 = 0;
      v27 = 0;
      v28 = v23;
      do
      {
        while ( !(*(_BYTE *)(v24 + v25 + 12) & 0x40) )
        {
          v26 += *(_DWORD *)(v24 + v25);
          ++v27;
          v25 += 20;
          if ( *((_DWORD *)v28 + 10) <= v27 )
            goto LABEL_24;
        }
        v29 = v28;
        ++v27;
        BaseModel::bindTexture(v28, v24 + v25);
        v30 = (const GLvoid *)VertexBuffer::getPointer(*((VertexBuffer **)v29 + 4), 3 * v26);
        glDrawElements(4u, 3 * *(_DWORD *)(*((_DWORD *)v29 + 8) + v25), 0x1403u, v30);
        v28 = v29;
        v24 = *((_DWORD *)v29 + 8);
        v31 = (_DWORD *)(v24 + v25);
        v25 += 20;
        v26 += *v31;
      }
      while ( *((_DWORD *)v29 + 10) > v27 );
    }
LABEL_24:
    GlStat::cullFace((GlStat *)&GlStat::glStat, 1);
    glDepthMask(1u);
    glBlendFunc(0x302u, 0x303u);
    NrMatrix::~NrMatrix();
  }
}
// B7E14: using guessed type int __cdecl glVertexAttribPointer(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);

//----- (00175130) --------------------------------------------------------
signed int __cdecl K_InitMotionBone(int a1)
{
  char *v1; // ebp
  float *v2; // esi
  int v3; // ebp
  signed __int16 *v4; // edi
  signed int result; // eax
  float v6; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm1_4

  v1 = (char *)&unk_405DF0 + 288 * *(_DWORD *)(a1 + 23572);
  v2 = (float *)(v1 + 4);
  v3 = (int)(v1 + 292);
  v4 = *(signed __int16 **)(*(_DWORD *)(a1 + 23972) + 12);
  do
  {
    result = v4[14];
    v6 = (float)v4[12] / 16000.0;
    v7 = (float)v4[13] / 16000.0;
    v8 = (float)result / 16000.0;
    *v2 = v6;
    v2[1] = v7;
    v2[2] = v8;
    v2[3] = fsqrt((float)((float)(v6 * v6) + (float)(v7 * v7)) + (float)(v8 * v8));
    v2 += 4;
    v4 += 16;
  }
  while ( v2 != (float *)v3 );
  return result;
}

//----- (00175210) --------------------------------------------------------
signed int __cdecl K_InitMotionBoneDefault(int a1)
{
  signed __int16 *v1; // edi
  char *v2; // ebp
  float *v3; // esi
  int v4; // ebp
  signed int result; // eax
  float v6; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm1_4

  v1 = (signed __int16 *)&unk_292F20;
  v2 = (char *)&unk_405DF0 + 288 * *(_DWORD *)(a1 + 23572);
  v3 = (float *)(v2 + 4);
  v4 = (int)(v2 + 292);
  do
  {
    result = v1[2];
    v6 = (float)*v1 / 1000.0;
    v7 = (float)v1[1] / 1000.0;
    v8 = (float)result / 1000.0;
    *v3 = v6;
    v3[1] = v7;
    v3[2] = v8;
    v3[3] = fsqrt((float)((float)(v6 * v6) + (float)(v7 * v7)) + (float)(v8 * v8));
    v3 += 4;
    v1 += 3;
  }
  while ( v3 != (float *)v4 );
  return result;
}