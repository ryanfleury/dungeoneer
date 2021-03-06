#define AUDIO_SOURCE_MAX 512

#define AUDIO_TYPE_LIST                          \
AudioType(master,           "Master")            \
AudioType(background_music, "Background Music")  \
AudioType(entities,         "Entities")          \
AudioType(environment,      "Environment")       \
AudioType(user_interface,   "User Interface")

enum
{
#define AudioType(code_name, str_name) AUDIO_##code_name,
    AUDIO_TYPE_LIST
#undef AudioType
        AUDIO_MAX
};

internal char *
AudioTypeName(i32 type)
{
    local_persist char *names[AUDIO_MAX] = {
#define AudioType(code_name, str_name) str_name,
        AUDIO_TYPE_LIST
#undef AudioType
    };
    
    Assert(type >= 0 && type < AUDIO_MAX);
    return names[type];
}

typedef struct AudioSource AudioSource;
struct AudioSource
{
    Sound *sound;
    i32 volume_type;
    f32 volume;
    f32 pitch;
    b32 playing;
    b32 distanced;
    b32 loop;
    v3 position;
    f64 play_position;
};

typedef struct Audio Audio;
struct Audio
{
    AudioSource sources[AUDIO_SOURCE_MAX];
    b32 source_reserved[AUDIO_SOURCE_MAX];
    f32 volumes[AUDIO_MAX];
    f32 modifiers[AUDIO_MAX];
    v3 listener_position;
};

typedef i32 AudioSourceID; 