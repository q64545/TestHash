#Compare different hash functions
exp @1
    Num of unique random string is 9086367
    Hash size is 1048576
    HASH_SIZE / NUMS_RANDOM_STR is 0.115390794848

    func @0 tf.string_to_hash_bucket_fast

        Calculate time is 11.6317679882s
        Conflict nums is 8037991
        Conflict rate is 0.884620993187

    func @1 tf.string_to_hash_bucket_strong

        Calculate time is 11.0532441139s
        Conflict nums is 8038816
        Conflict rate is 0.884633415104

    func @2 pino_hash_op

        Calculate time is 12.8425891399s
        Conflict nums is 8038002
        Conflict rate is 0.884622203792

    func @3 basic_hash_op

        @BKDRHash
            Calculate time is 12.0634701252s
            Conflict nums is 8037962
            Conflict rate is 0.884617801592

        @SDBMHash
            Calculate time is 11.683193922s
            Conflict nums is 8037978
            Conflict rate is 0.884619562472

        @RSHash
            Calculate time is 11.8271329403s
            Conflict nums is 8037955
            Conflict rate is 0.884617031207

        @APHash
            Calculate time is 14.6870570183s
            Conflict nums is 8037965
            Conflict rate is 0.884618131757

        @JSHash
            Calculate time is 11.9153380394s
            Conflict nums is 8038023
            Conflict rate is 0.884624514946

        @DEKHash
            Calculate time is 12.0011000633s
            Conflict nums is 8038009
            Conflict rate is 0.884622974177

        @FNVHash
            Calculate time is 11.3874430656s
            Conflict nums is 8037958
            Conflict rate is 0.884617361372

        @DJBHash
            Calculate time is 11.671847105s
            Conflict nums is 8038034
            Conflict rate is 0.884625725551

        @DJB2Hash
            Calculate time is 12.435874939s
            Conflict nums is 8037993
            Conflict rate is 0.884621213297

        @PJWHash
            Calculate time is 12.2058038712s
            Conflict nums is 8893854
            Conflict rate is 0.978812984331

        @ELFHash
            Calculate time is 11.6762731075s
            Conflict nums is 8893854
            Conflict rate is 0.978812984331

        @JAVAHash
            Calculate time is 11.9837682247s
            Conflict nums is 8038023
            Conflict rate is 0.884624514946


exp @2
    Num of unique random string is 9086367
    Hash size is 4194304
    HASH_SIZE / NUMS_RANDOM_STR is 0.461563179392

    func @0 tf.string_to_hash_bucket_fast

        Calculate time is 12.3803920746s
        Conflict nums is 5374471
        Conflict rate is 0.591487334817

    func @1 tf.string_to_hash_bucket_strong

        Calculate time is 10.792249918s
        Conflict nums is 5374508
        Conflict rate is 0.591439008748

    func @2 pino_hash_op

        Calculate time is 11.3727741241s
        Conflict nums is 5374926
        Conflict rate is 0.591537409836

    func @3 basic_hash_op

        @BKDRHash
            Calculate time is 12.016065836s
            Conflict nums is 5372267
            Conflict rate is 0.591244773626

        @SDBMHash

            Calculate time is 11.0210659504s
            Conflict nums is 5384759
            Conflict rate is 0.592567082476

        @RSHash

            Calculate time is 12.7708671093s
            Conflict nums is 5374043
            Conflict rate is 0.591387837712

        @APHash

            Calculate time is 11.8240659237s
            Conflict nums is 5373317
            Conflict rate is 0.59130794487

        @JSHash

            Calculate time is 13.8055989742s
            Conflict nums is 5404705
            Conflict rate is 0.594762044781

        @DEKHash

            Calculate time is 12.8126158714s
            Conflict nums is 5404516
            Conflict rate is 0.594741246232

        @FNVHash

            Calculate time is 11.069163084s
            Conflict nums is 5372407
            Conflict rate is 0.591207803704

        @DJBHash

            Calculate time is 11.8476119041s
            Conflict nums is 5403085
            Conflict rate is 0.594583771497

        @DJB2Hash

            Calculate time is 14.1249010563s
            Conflict nums is 5404096
            Conflict rate is 0.594695027232

        @PJWHash

            Calculate time is 13.0881929398s
            Conflict nums is 8317136
            Conflict rate is 0.915261205576

        @ELFHash

            Calculate time is 12.2128949165s
            Conflict nums is 8317136
            Conflict rate is 0.915261205576

        @JAVAHash

            Calculate time is 10.8355050087s
            Conflict nums is 5403692
            Conflict rate is 0.594650568956


exp @3
    Num of random string is 9087172
    Hash size is 16777216
    HASH_SIZE / NUMS_RANDOM_STR is 1.84625271757

    func @0 tf.string_to_hash_bucket_fast

        Calculate time is 12.0596909523s
        Conflict nums is 2076187
        Conflict rate is 0.228474491294

    func @1 tf.string_to_hash_bucket_strong

        Calculate time is 10.9286429882s
        Conflict nums is 2077043
        Conflict rate is 0.228568690017

    func @2 pino_hash_op

        Calculate time is 12.4651830196s
        Conflict nums is 2077968
        Conflict rate is 0.228670481862

    func @3 basic_hash_op

        @BKDRHash

            Calculate time is 11.0454051495s
            Conflict nums is 2074330
            Conflict rate is 0.228270137288

        @SDBMHash
        @RSHash
        @APHash
        @JSHash
        @DEKHash
        @FNVHash
        @DJBHash
        @DJB2Hash
        @PJWHash
        @ELFHash
        @JAVAHash


exp @4
    Num of random string is 9086367
    Hash size is 67108864
    HASH_SIZE / NUMS_RANDOM_STR is 7.38501087027

    func @0 tf.string_to_hash_bucket_fast

        Calculate time is 11.1568741798s
        Conflict nums is 596695
        Conflict rate is 0.0656634429281

    func @1 tf.string_to_hash_bucket_strong

        Calculate time is 12.7320871353s
        Conflict nums is 597377
        Conflict rate is 0.06573849378

    func @2 pino_hash_op

        Calculate time is 11.0531711578s
        Conflict nums is 599310
        Conflict rate is 0.0659512112239

    func @3 basic_hash_op

        @BKDRHash

            Calculate time is 10.8580389023s
            Conflict nums is 596901
            Conflict rate is 0.065686112247

        @SDBMHash
        @RSHash
        @APHash
        @JSHash
        @DEKHash
        @FNVHash
        @DJBHash
        @DJB2Hash
        @PJWHash
        @ELFHash
        @JAVAHash


exp @5
    Num of random string is 9087172
    Hash size is 268435456
    HASH_SIZE / NUMS_RANDOM_STR is 29.5400434811

    func @0 tf.string_to_hash_bucket_fast

        Calculate time is 11.0579340458s
        Conflict nums is 161478
        Conflict rate is 0.0177698848443

    func @1 tf.string_to_hash_bucket_strong

        Calculate time is 11.0191509724s
        Conflict nums is 162140
        Conflict rate is 0.0178427347914

    func @2 pino_hash_op

        Calculate time is 11.6627979279s
        Conflict nums is 162792
        Conflict rate is 0.0179144842862

    func @3 basic_hash_op

        @BKDRHash

            Calculate time is 10.7791290283s
            Conflict nums is 161938
            Conflict rate is 0.0178205056535

        @SDBMHash
        @RSHash
        @APHash
        @JSHash
        @DEKHash
        @FNVHash
        @DJBHash
        @DJB2Hash
        @PJWHash
        @ELFHash
        @JAVAHash


exp @7
    Num of random string is 9087172
    Hash size is 536870912
    HASH_SIZE / NUMS_RANDOM_STR is 59.0800869621

    func @0 tf.string_to_hash_bucket_fast

        Calculate time is 11.490858078s
        Conflict nums is 86497
        Conflict rate is 0.00951858289906

    func @1 tf.string_to_hash_bucket_strong

        Calculate time is 10.9801001549s
        Conflict nums is 86787
        Conflict rate is 0.0095504960179

    func @2 pino_hash_op

        Calculate time is 11.0194218159s
        Conflict nums is 87232
        Conflict rate is 0.00959946614854

    func @3 basic_hash_op

        @BKDRHash

            Calculate time is 11.9726400375s
            Conflict nums is 86631
            Conflict rate is 0.00953332896087

        @SDBMHash
        @RSHash
        @APHash
        @JSHash
        @DEKHash
        @FNVHash
        @DJBHash
        @DJB2Hash
        @PJWHash
        @ELFHash
        @JAVAHash


exp @8
    Num of random string is 9087172
    Hash size is 1073741824
    HASH_SIZE / NUMS_RANDOM_STR is 118.160173924

    func @0 tf.string_to_hash_bucket_fast

        Calculate time is 13.1547999382s
        Conflict nums is 48528
        Conflict rate is 0.00534027528036

    func @1 tf.string_to_hash_bucket_strong

        Calculate time is 12.2062988281s
        Conflict nums is 48701
        Conflict rate is 0.00535931310643

    func @2 pino_hash_op

        Calculate time is 11.2301700115s
        Conflict nums is 48995
        Conflict rate is 0.00539166640623

    func @3 basic_hash_op

        @BKDRHash

            Calculate time is 10.8694009781s
            Conflict nums is 48868
            Conflict rate is 0.00537769066108

        @SDBMHash
        @RSHash
        @APHash
        @JSHash
        @DEKHash
        @FNVHash
        @DJBHash
        @DJB2Hash
        @PJWHash
        @ELFHash
        @JAVAHash