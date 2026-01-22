#pragma once

struct f_name_t
{
    unordered_map<int32_t, string> name_cache;
    mutex cache_mutex;
    uintptr_t chunk_cache[1024]{};

    std::int32_t get_index(std::int32_t index)
    {
        if (index == 0)
            return 0;

        std::int32_t v3 = std::rotl(static_cast<std::uint32_t>((index - 1) ^ 0x408CE8FF), 18) + 1;
        std::int32_t v4 = 0x5C0B8A4D;

        if (v3)
            v4 = v3;

        return v4;
    }


    std::string get_string(std::int32_t index)
    {
        std::int32_t decrypted_index = get_index(index);

    resolve_address:
        if (decrypted_index <= 0)
            return "";

        std::uint32_t chunk_index = static_cast<std::uint32_t>(decrypted_index) >> 16;
        std::uint16_t name_entry_index = static_cast<std::uint16_t>(decrypted_index);

        std::uintptr_t gnames_addr = hv::state.process_base + 0x1777E080;
        std::uintptr_t chunk_ptr_addr = gnames_addr + (static_cast<std::uint64_t>(chunk_index) + 2) * 8;
        std::uintptr_t chunk_ptr = hv::read<std::uintptr_t>(chunk_ptr_addr);

        if (!chunk_ptr)
            return "";

        std::uintptr_t name_pool_chunk = chunk_ptr + (2 * name_entry_index);
        std::uint16_t header = hv::read<std::uint16_t>(name_pool_chunk);

        if (static_cast<std::int16_t>(header) < 0)
            return "";

        std::int32_t raw_len = header & 0x3FF;

        if (raw_len == 112)
        {
            std::int32_t new_index = hv::read<std::int32_t>(name_pool_chunk + 6);
            decrypted_index = get_index(new_index);
            goto resolve_address;
        }

        std::int32_t length = raw_len ^ 0x70;

        if (length <= 0 || length > 1024)
            return "";

        std::vector<std::uint8_t> buffer(length);
        hv::read_raw(name_pool_chunk + 2, buffer.data(), length);

        std::string result(length, '\0');
        std::uint16_t offset = static_cast<std::uint16_t>(24319 - 6431 * length);
        std::uint8_t key = static_cast<std::uint8_t>(-31 * length - 120);

        for (std::int32_t i = 0; i < length; ++i)
        {
            std::uint32_t idx = (offset + i) % length;
            result[i] = std::rotl(static_cast<std::uint8_t>(key ^ buffer[idx]), 5);
        }

        return result;
    }

    string get_fname(int32_t index)
    {
        return get_string(index);
    }
};

inline f_name_t* FName = new f_name_t();
