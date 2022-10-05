#ifndef MAIN_HPP
#define MAIN_HPP
#include <iostream>
#include <vector>
class Main
{
public:
    /* Integers */
    unsigned int s_to_n_db {100};

    /* Sound Card */
    int32_t latency_calcs;

    /* Booleans */
    bool codec_started;
    bool in_test_mode {false};
    bool closing {false};
    bool frame_pending {false};
    bool last_ptt {false};

    /* C++ pendant to Visual BASIC Bytes8 type */
    unsigned char last_acked_data_frame_type {0};

    /* Properties */
    bool sound_is_playing() const;
private:
    /* Sound Card */
    int32_t capture_buffer_size;
    int32_t next_capture_offset;
    int32_t notify_size {2048};
    int32_t measured_tr_latency;
    int32_t average_tr_latency;
    int64_t sound_card_samples;

    /* Integers */
    int32_t repeat_cnt;
    const int32_t number_record_notifications {32};//constexpr instead of const?
    int32_t bmp_spectrum_width {256};
    int32_t bmp_spectrum_height {62};
    unsigned int ptt_on_count {0};
    unsigned int ptt_off_count {0};

    /* Booleans */
    bool sc_capturing;
    bool graphics_cleared {false};
    bool sound_stream_play {false};
    bool latency_calculated {true};
    bool busy_status {false};

    /* Dates */
    /* No equivalent type in C++, commented out for now. */
    /* date next_play;
     * date last_sound_card_sample;
     * date codec_started;
     * date next_graphics_reset;
     * date sound_card_sample_start;
     * date ptt_release;
     * date ptt_apply;
     */


    /* Doubles */
    double phase;
    double ptt_on_level_sum;
    double ptt_off_level_sum;

    /* Arrays */
    double car_freq();
    std::vector<unsigned char> to_send;
    std::vector<unsigned char> sym_to_send;
    std::vector<int32_t> samples;
    std::vector<double> phase_inc;
    std::vector<double> cp_phase_offset;
    std::vector<unsigned char> host_ib_data_cmd_buffer;

    /* Structures */
    struct device_description_t;

    /* Strings */
//    std::string tcpip_connection_id;
};
#endif // MAIN_HPP
