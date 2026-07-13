#ifndef HDA_MOD_H
#define HDA_MOD_H

#include <stdint.h>

#define HDA_MAX_CODECS        15
#define HDA_MAX_SD            16
#define HDA_CORB_ENTRY_SIZE   4
#define HDA_RIRB_ENTRY_SIZE   8
#define HDA_CORB_SIZE         256
#define HDA_RIRB_SIZE         256
#define HDA_BDL_ENTRIES       32
#define HDA_PCM_BUFFER_SIZE   (128 * 1024)

#define HDA_GCAP       0x00
#define HDA_VMIN       0x02
#define HDA_VMAJ       0x03
#define HDA_OUTPAY     0x04
#define HDA_INPAY      0x06
#define HDA_GCTL       0x08
#define HDA_WAKEEN     0x0C
#define HDA_STATESTS   0x0E
#define HDA_GSTS       0x10
#define HDA_INTCTL     0x20
#define HDA_INTSTS     0x24
#define HDA_WALCLK     0x30
#define HDA_SSYNC      0x34

#define HDA_CORBBASE   0x40
#define HDA_CORBUBASE  0x44
#define HDA_CORBWP     0x48
#define HDA_CORBRP     0x4A
#define HDA_CORBCTL    0x4C
#define HDA_CORBSTS    0x4D
#define HDA_CORBSIZE   0x4E

#define HDA_RIRBBASE   0x50
#define HDA_RIRBUBASE  0x54
#define HDA_RIRBWP     0x58
#define HDA_RIRBCNT    0x5A
#define HDA_RIRBCTL    0x5C
#define HDA_RIRBSTS    0x5D
#define HDA_RIRBSIZE   0x5E

#define HDA_IC         0x68
#define HDA_IRII       0x64
#define HDA_ICOI       0x60

#define HDA_DPLBASE    0x70
#define HDA_DPUBASE    0x74

#define HDA_GCTL_CRST  (1u << 0)

#define HDA_CORBCTL_RUN   (1u << 1)
#define HDA_CORBSIZE_256  (0x00u << 28)

#define HDA_RIRBCTL_RUN   (1u << 1)
#define HDA_RIRBSIZE_256  (0x00u << 28)
#define HDA_RIRBINTFLAG   (1u << 2)

#define HDA_ICB   (1u << 0)
#define HDA_ICV   (1u << 1)

#define HDA_WAKEEN_SDI  0x7FFF

#define HDA_INTS_GLB  (1u << 31)

#define HDA_GSTS_FSTS (1u << 1)

#define HDA_SD_BASE_IN   0x80
#define HDA_SD_BASE_OUT  0x100
#define HDA_SD_STEP      0x20

#define HDA_SDCTL_RUN   (1u << 0)
#define HDA_SDCTL_SRST  (1u << 1)
#define HDA_SDCTL_DEIE  (1u << 2)
#define HDA_SDCTL_FEIE  (1u << 3)
#define HDA_SDCTL_STRIPE  (0x3u << 16)
#define HDA_SDCTL_TP   (1u << 18)
#define HDA_SDCTL_DIR_SHIFT 19
#define HDA_SDCTL_DIR_MASK  (1u << 19)

#define HDA_SDCTL_STRM_TAG_SHIFT 20
#define HDA_SDCTL_STRM_TAG_MASK  (0xFu << 20)

#define HDA_SDSTS_FIFORDY (1u << 2)
#define HDA_SDSTS_DE     (1u << 4)
#define HDA_SDSTS_FE     (1u << 5)
#define HDA_SDSTS_BCIS   (1u << 6)

#define HDA_SDFMT_BITS_SHIFT 4
#define HDA_SDFMT_BITS_MASK  (0x7u << 4)
#define HDA_SDFMT_BITS_8     (0x0u << 4)
#define HDA_SDFMT_BITS_16    (0x1u << 4)
#define HDA_SDFMT_BITS_20    (0x2u << 4)
#define HDA_SDFMT_BITS_24    (0x3u << 4)
#define HDA_SDFMT_BITS_32    (0x4u << 4)
#define HDA_SDFMT_BASE_SHIFT 8
#define HDA_SDFMT_RATE_48KHZ (0x6u << 8)

#define HDA_BDL_AIFLAG    (1u << 0)

#define HDA_VERB_GET_PARAM      0xF00
#define HDA_VERB_SET_STREAM     0x706
#define HDA_VERB_SET_AMP        0x705
#define HDA_VERB_SET_CONVERTER_FMT 0x701
#define HDA_VERB_SET_POWER_STATE   0x705
#define HDA_VERB_GET_PIN_WIDGET_CTRL 0xF07
#define HDA_VERB_SET_PIN_WIDGET_CTRL 0x707
#define HDA_VERB_SET_OUTPUT_AMP 0x702
#define HDA_VERB_GET_CONNECTION_LIST 0xF0E
#define HDA_VERB_GET_CONNECTION_SEL 0xF03

#define HDA_PARAM_VENDOR_ID       0x00
#define HDA_PARAM_REVISION        0x02
#define HDA_PARAM_SUB_NODE_COUNT  0x04
#define HDA_PARAM_FUNCTION_GROUP  0x05
#define HDA_PARAM_AUDIO_WIDGET    0x09
#define HDA_PARAM_PCM             0x0A
#define HDA_PARAM_STREAM_FORMATS  0x0B
#define HDA_PARAM_PIN_CAPS        0x0C
#define HDA_PARAM_AMP_CAPS        0x12

#define HDA_PIN_CAP_IS_EAPD  (1u << 16)

typedef volatile struct {
    uint32_t ctl;
    uint32_t sts;
    uint32_t lpib;
    uint32_t cbl;
    uint32_t lvi;
    uint32_t fifow;
    uint32_t fifos;
    uint32_t fmt;
    uint32_t rsv[7];
    uint32_t bdpl;
    uint32_t bdpu;
} hda_sd_t;

typedef struct {
    uint32_t addr_low;
    uint32_t addr_high;
    uint32_t length;
    uint32_t ioc;
} __attribute__((packed)) hda_bdl_entry_t;

typedef struct {
    uint32_t verb;
    uint32_t response;
} hda_codec_cmd_t;

typedef struct {
    uint8_t   active;
    uint8_t   addr;
    uint16_t  vendor_id;
    uint16_t  device_id;
    uint8_t   revision;
    uint8_t   afg_node;    
    uint8_t   num_widgets;
    uint8_t   start_widget;
} hda_codec_info_t;

typedef struct {
    uint8_t   active;
    uint8_t   node_id;
    uint8_t   type;
    uint16_t  caps;
    uint8_t   pcm_rates;
    uint8_t   pcm_bits;
    uint8_t   pcm_formats;
    uint8_t   pin_caps;
    uint8_t   num_connections;
    uint8_t   connections[16];
} hda_widget_info_t;

#define HDA_WIDGET_TYPE_DAC         0x00
#define HDA_WIDGET_TYPE_ADC         0x01
#define HDA_WIDGET_TYPE_MIXER       0x02
#define HDA_WIDGET_TYPE_SELECTOR    0x03
#define HDA_WIDGET_TYPE_PIN         0x04
#define HDA_WIDGET_TYPE_POWER       0x05
#define HDA_WIDGET_TYPE_VOLUME_KNOB 0x06
#define HDA_WIDGET_TYPE_BEEP        0x07
#define HDA_WIDGET_TYPE_VENDOR      0x0F

#endif
