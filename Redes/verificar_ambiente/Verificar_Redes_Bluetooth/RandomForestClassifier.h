#pragma once
#include <cstdarg>
namespace Eloquent {
    namespace ML {
        namespace Port {
            class RandomForest {
                public:
                    /**
                    * Predict class for features vector
                    */
                    int predict(float *x) {
                        uint8_t votes[3] = { 0 };
                        // tree #1
                        if (x[12] <= -41.5) {
                            if (x[11] <= -72.5) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[19] <= -40.0) {
                                    votes[2] += 1;
                                }

                                else {
                                    if (x[21] <= -45.5) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                        }

                        else {
                            if (x[2] <= -73.5) {
                                votes[2] += 1;
                            }

                            else {
                                if (x[21] <= -44.0) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[3] <= -66.0) {
                                        if (x[4] <= -59.0) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }

                                    else {
                                        if (x[4] <= -29.0) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[20] <= -44.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                if (x[7] <= -45.5) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    if (x[0] <= -90.5) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        votes[0] += 1;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #2
                        if (x[10] <= -58.5) {
                            if (x[10] <= -70.5) {
                                if (x[2] <= -73.0) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                if (x[22] <= -139.5) {
                                    votes[0] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        else {
                            if (x[11] <= -39.5) {
                                votes[0] += 1;
                            }

                            else {
                                if (x[15] <= -40.0) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[24] <= -34.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[25] <= -90.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[0] <= -46.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                if (x[22] <= -46.5) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    if (x[20] <= -46.0) {
                                                        votes[0] += 1;
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #3
                        if (x[3] <= -65.5) {
                            if (x[3] <= -73.0) {
                                if (x[2] <= -73.0) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                if (x[24] <= -77.5) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }
                        }

                        else {
                            if (x[0] <= -93.0) {
                                if (x[4] <= -32.5) {
                                    votes[0] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                votes[0] += 1;
                            }
                        }

                        // tree #4
                        if (x[18] <= -40.0) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[23] <= -79.0) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[23] <= -30.5) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[6] <= -42.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[11] <= -82.0) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[10] <= -76.5) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                if (x[15] <= -44.5) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    if (x[0] <= -44.0) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        if (x[20] <= -46.0) {
                                                            votes[0] += 1;
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #5
                        if (x[10] <= -71.0) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[9] <= -89.5) {
                                votes[0] += 1;
                            }

                            else {
                                if (x[5] <= -41.5) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[8] <= -38.5) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        if (x[23] <= -31.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[22] <= -91.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                if (x[25] <= -44.5) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    if (x[0] <= -47.5) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        votes[0] += 1;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #6
                        if (x[2] <= -74.5) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[23] <= -76.5) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[21] <= -44.5) {
                                    if (x[9] <= -87.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    if (x[13] <= -42.0) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        if (x[7] <= -36.0) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[2] <= -31.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                if (x[22] <= -45.0) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    if (x[20] <= -46.0) {
                                                        votes[0] += 1;
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #7
                        if (x[11] <= -72.5) {
                            if (x[10] <= -58.5) {
                                if (x[7] <= -88.0) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                votes[0] += 1;
                            }
                        }

                        else {
                            if (x[6] <= -42.0) {
                                votes[0] += 1;
                            }

                            else {
                                if (x[10] <= -61.5) {
                                    votes[2] += 1;
                                }

                                else {
                                    if (x[3] <= -26.5) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[21] <= -44.5) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            if (x[20] <= -46.0) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #8
                        if (x[18] <= -40.0) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[23] <= -79.0) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[13] <= -41.0) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[0] <= -92.0) {
                                        if (x[14] <= -40.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }

                                    else {
                                        if (x[17] <= -87.5) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }
                                }
                            }
                        }

                        // tree #9
                        if (x[19] <= -40.0) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[3] <= -65.5) {
                                if (x[1] <= -73.0) {
                                    if (x[11] <= -80.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                if (x[11] <= -39.5) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[22] <= -46.5) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[20] <= -46.0) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[23] <= -32.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                if (x[9] <= -43.5) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #10
                        if (x[17] <= -38.5) {
                            if (x[14] <= -40.5) {
                                votes[0] += 1;
                            }

                            else {
                                if (x[19] <= -40.0) {
                                    votes[2] += 1;
                                }

                                else {
                                    if (x[15] <= -40.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                        }

                        else {
                            if (x[12] <= -42.5) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[2] <= -71.0) {
                                    if (x[1] <= -68.5) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    if (x[9] <= -79.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[0] <= -88.5) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            if (x[24] <= -79.0) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #11
                        if (x[3] <= -66.5) {
                            if (x[3] <= -76.5) {
                                if (x[4] <= -53.0) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                if (x[10] <= -70.5) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        else {
                            if (x[17] <= -87.5) {
                                if (x[2] <= -35.5) {
                                    votes[0] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                if (x[9] <= -42.0) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[7] <= -38.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[10] <= -25.0) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[20] <= -46.0) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #12
                        if (x[18] <= -40.0) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[23] <= -78.0) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[12] <= -41.5) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[0] <= -94.5) {
                                        if (x[24] <= -37.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }
                        }

                        // tree #13
                        if (x[2] <= -73.5) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[10] <= -58.5) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[10] <= -23.5) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[9] <= -43.5) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                        }

                        // tree #14
                        if (x[1] <= -66.5) {
                            if (x[17] <= -38.5) {
                                if (x[24] <= -31.5) {
                                    if (x[11] <= -77.5) {
                                        if (x[12] <= -43.5) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    votes[2] += 1;
                                }
                            }

                            else {
                                if (x[3] <= -66.5) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }
                        }

                        else {
                            if (x[19] <= -40.5) {
                                votes[2] += 1;
                            }

                            else {
                                if (x[23] <= -75.0) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[0] <= -44.0) {
                                        if (x[6] <= -43.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }

                                    else {
                                        if (x[8] <= -43.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[2] <= -33.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                if (x[25] <= -44.5) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    votes[0] += 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #15
                        if (x[2] <= -73.5) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[4] <= -56.0) {
                                if (x[10] <= -60.5) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }

                            else {
                                if (x[9] <= -85.0) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[15] <= -88.5) {
                                        if (x[11] <= -38.5) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                        }

                        // tree #16
                        if (x[4] <= -56.5) {
                            if (x[10] <= -66.5) {
                                votes[2] += 1;
                            }

                            else {
                                if (x[12] <= -43.5) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[23] <= -79.0) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }
                        }

                        else {
                            if (x[23] <= -41.5) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[20] <= -87.5) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[6] <= -44.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                        }

                        // tree #17
                        if (x[3] <= -72.0) {
                            if (x[22] <= -46.5) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[10] <= -68.0) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        else {
                            if (x[1] <= -65.5) {
                                votes[0] += 1;
                            }

                            else {
                                if (x[9] <= -84.0) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[15] <= -88.0) {
                                        if (x[7] <= -38.0) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                        }

                        // tree #18
                        if (x[18] <= -40.0) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[21] <= -43.5) {
                                if (x[8] <= -72.5) {
                                    if (x[6] <= -43.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    votes[2] += 1;
                                }
                            }

                            else {
                                if (x[11] <= -78.5) {
                                    if (x[24] <= -79.0) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }

                                else {
                                    if (x[23] <= -75.0) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        if (x[13] <= -42.5) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            if (x[20] <= -46.0) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                if (x[0] <= -92.5) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    votes[0] += 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #19
                        if (x[10] <= -60.5) {
                            if (x[2] <= -73.5) {
                                votes[2] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        else {
                            if (x[11] <= -77.5) {
                                votes[0] += 1;
                            }

                            else {
                                if (x[5] <= -41.5) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[6] <= -44.5) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[4] <= -64.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[17] <= -41.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                if (x[7] <= -45.5) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #20
                        if (x[3] <= -66.5) {
                            if (x[23] <= -41.5) {
                                if (x[3] <= -73.0) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                if (x[18] <= -40.0) {
                                    votes[2] += 1;
                                }

                                else {
                                    if (x[11] <= -70.5) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }
                            }
                        }

                        else {
                            if (x[13] <= -42.5) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[0] <= -93.0) {
                                    if (x[6] <= -87.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    if (x[2] <= -30.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[25] <= -44.5) {
                                            if (x[22] <= -45.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                if (x[5] <= -42.5) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }
                                }
                            }
                        }

                        // tree #21
                        if (x[24] <= -78.5) {
                            votes[1] += 1;
                        }

                        else {
                            if (x[19] <= -40.0) {
                                votes[2] += 1;
                            }

                            else {
                                if (x[2] <= -69.0) {
                                    if (x[4] <= -57.5) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    if (x[17] <= -87.5) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        if (x[0] <= -90.5) {
                                            if (x[11] <= -41.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }
                                }
                            }
                        }

                        // tree #22
                        if (x[23] <= -79.0) {
                            if (x[21] <= -91.0) {
                                if (x[18] <= -43.0) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        else {
                            if (x[12] <= -83.5) {
                                if (x[9] <= -36.5) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                if (x[10] <= -62.5) {
                                    if (x[2] <= -75.5) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    if (x[20] <= -44.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[23] <= -32.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[17] <= -44.0) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #23
                        if (x[2] <= -74.5) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[3] <= -65.5) {
                                if (x[1] <= -69.0) {
                                    if (x[11] <= -75.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                if (x[0] <= -93.0) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[9] <= -42.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[16] <= -43.0) {
                                            if (x[13] <= -42.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }
                                }
                            }
                        }

                        // tree #24
                        if (x[11] <= -72.5) {
                            if (x[10] <= -57.5) {
                                if (x[1] <= -71.0) {
                                    if (x[23] <= -37.5) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                votes[0] += 1;
                            }
                        }

                        else {
                            if (x[12] <= -42.0) {
                                votes[2] += 1;
                            }

                            else {
                                if (x[0] <= -91.0) {
                                    if (x[18] <= -40.5) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }
                        }

                        // tree #25
                        if (x[19] <= -40.0) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[23] <= -78.0) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[13] <= -41.0) {
                                    if (x[4] <= -53.0) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    if (x[3] <= -28.5) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[11] <= -41.0) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[7] <= -45.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                if (x[9] <= -45.0) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    if (x[0] <= -46.5) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        if (x[17] <= -44.0) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            votes[0] += 1;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #26
                        if (x[3] <= -65.0) {
                            if (x[19] <= -40.0) {
                                votes[2] += 1;
                            }

                            else {
                                if (x[0] <= -93.0) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[9] <= -36.5) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }
                        }

                        else {
                            if (x[13] <= -42.5) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[0] <= -92.0) {
                                    if (x[1] <= -40.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    if (x[21] <= -44.5) {
                                        if (x[6] <= -43.0) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }
                        }

                        // tree #27
                        if (x[13] <= -41.5) {
                            if (x[2] <= -74.0) {
                                votes[2] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        else {
                            if (x[19] <= -40.5) {
                                votes[2] += 1;
                            }

                            else {
                                if (x[3] <= -66.5) {
                                    if (x[4] <= -59.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    if (x[1] <= -35.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[20] <= -43.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[7] <= -45.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #28
                        if (x[18] <= -40.0) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[3] <= -66.5) {
                                if (x[10] <= -56.0) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }

                            else {
                                if (x[2] <= -30.0) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[25] <= -44.5) {
                                        if (x[20] <= -45.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[9] <= -46.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }
                        }

                        // tree #29
                        if (x[23] <= -78.0) {
                            if (x[23] <= -89.5) {
                                votes[2] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        else {
                            if (x[19] <= -40.0) {
                                votes[2] += 1;
                            }

                            else {
                                if (x[12] <= -41.0) {
                                    if (x[25] <= -43.5) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }

                                else {
                                    if (x[1] <= -35.5) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[9] <= -43.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[0] <= -46.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #30
                        if (x[18] <= -40.0) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[3] <= -66.5) {
                                if (x[9] <= -87.0) {
                                    votes[0] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                if (x[9] <= -85.0) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[24] <= -31.5) {
                                        if (x[25] <= -45.0) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                        }

                        // tree #31
                        if (x[10] <= -70.5) {
                            if (x[3] <= -71.0) {
                                votes[2] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        else {
                            if (x[15] <= -40.0) {
                                if (x[13] <= -43.0) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[21] <= -45.0) {
                                        if (x[0] <= -88.5) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }

                            else {
                                if (x[11] <= -85.5) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[9] <= -36.5) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        if (x[7] <= -36.0) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[20] <= -89.0) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #32
                        if (x[12] <= -41.0) {
                            if (x[8] <= -81.5) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[3] <= -70.5) {
                                    if (x[17] <= -86.5) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        else {
                            if (x[10] <= -58.0) {
                                if (x[4] <= -59.0) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                if (x[9] <= -42.0) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[3] <= -26.5) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[22] <= -46.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[25] <= -44.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                if (x[20] <= -46.0) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #33
                        if (x[2] <= -73.5) {
                            if (x[25] <= -93.0) {
                                if (x[9] <= -74.0) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                votes[2] += 1;
                            }
                        }

                        else {
                            if (x[3] <= -65.5) {
                                if (x[23] <= -77.0) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }

                            else {
                                if (x[25] <= -93.5) {
                                    if (x[9] <= -45.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    if (x[12] <= -43.0) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        if (x[21] <= -44.5) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            if (x[0] <= -92.0) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #34
                        if (x[1] <= -64.0) {
                            if (x[18] <= -40.0) {
                                votes[2] += 1;
                            }

                            else {
                                if (x[3] <= -66.5) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }
                        }

                        else {
                            if (x[20] <= -90.5) {
                                votes[0] += 1;
                            }

                            else {
                                if (x[10] <= -56.5) {
                                    if (x[0] <= -42.5) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        if (x[19] <= -44.5) {
                                            votes[2] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                }

                                else {
                                    if (x[0] <= -90.5) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        if (x[17] <= -87.0) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }
                                }
                            }
                        }

                        // tree #35
                        if (x[19] <= -40.0) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[13] <= -41.0) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[10] <= -58.5) {
                                    if (x[23] <= -79.0) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }

                                else {
                                    if (x[4] <= -29.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[14] <= -42.0) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[11] <= -43.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                if (x[22] <= -46.5) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #36
                        if (x[2] <= -73.5) {
                            if (x[18] <= -40.0) {
                                votes[2] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        else {
                            if (x[1] <= -70.5) {
                                if (x[23] <= -80.5) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }

                            else {
                                if (x[5] <= -43.5) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[1] <= -29.5) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        if (x[0] <= -89.5) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }
                                }
                            }
                        }

                        // tree #37
                        if (x[24] <= -78.0) {
                            if (x[24] <= -87.5) {
                                if (x[10] <= -72.5) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        else {
                            if (x[19] <= -40.0) {
                                votes[2] += 1;
                            }

                            else {
                                if (x[9] <= -83.5) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[20] <= -41.5) {
                                        if (x[20] <= -87.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }

                                    else {
                                        if (x[0] <= -88.5) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            if (x[2] <= -30.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                if (x[22] <= -46.5) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #38
                        if (x[12] <= -41.0) {
                            if (x[24] <= -41.0) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[19] <= -40.0) {
                                    votes[2] += 1;
                                }

                                else {
                                    if (x[0] <= -43.5) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }
                            }
                        }

                        else {
                            if (x[23] <= -79.0) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[18] <= -40.5) {
                                    votes[2] += 1;
                                }

                                else {
                                    if (x[0] <= -92.0) {
                                        if (x[16] <= -43.0) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }

                                    else {
                                        if (x[11] <= -40.0) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[17] <= -87.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #39
                        if (x[19] <= -40.0) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[12] <= -41.5) {
                                if (x[10] <= -76.5) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                if (x[24] <= -78.5) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[11] <= -78.5) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[17] <= -85.5) {
                                            if (x[3] <= -63.0) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }
                                }
                            }
                        }

                        // tree #40
                        if (x[19] <= -40.0) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[4] <= -58.5) {
                                votes[0] += 1;
                            }

                            else {
                                if (x[2] <= -63.0) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[20] <= -44.5) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[2] <= -30.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[9] <= -43.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                if (x[22] <= -46.5) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #41
                        if (x[4] <= -56.5) {
                            if (x[2] <= -72.5) {
                                votes[2] += 1;
                            }

                            else {
                                if (x[24] <= -79.0) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }
                        }

                        else {
                            if (x[5] <= -42.5) {
                                votes[0] += 1;
                            }

                            else {
                                if (x[11] <= -85.5) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[7] <= -31.5) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        if (x[20] <= -91.0) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                }
                            }
                        }

                        // tree #42
                        if (x[19] <= -40.0) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[1] <= -70.5) {
                                if (x[4] <= -55.0) {
                                    votes[0] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                if (x[20] <= -90.5) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[5] <= -43.5) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[8] <= -37.5) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            if (x[4] <= -33.0) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                if (x[12] <= -43.0) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    if (x[22] <= -45.5) {
                                                        votes[0] += 1;
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #43
                        if (x[10] <= -58.0) {
                            if (x[18] <= -40.0) {
                                votes[2] += 1;
                            }

                            else {
                                if (x[9] <= -136.0) {
                                    votes[0] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        else {
                            if (x[15] <= -39.0) {
                                votes[0] += 1;
                            }

                            else {
                                if (x[0] <= -90.5) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[3] <= -26.5) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[22] <= -45.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                }
                            }
                        }

                        // tree #44
                        if (x[10] <= -58.0) {
                            if (x[2] <= -75.0) {
                                votes[2] += 1;
                            }

                            else {
                                if (x[16] <= -132.5) {
                                    votes[0] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        else {
                            if (x[0] <= -94.5) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[16] <= -85.5) {
                                    if (x[15] <= -40.5) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }
                        }

                        // tree #45
                        if (x[10] <= -71.0) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[2] <= -64.0) {
                                if (x[1] <= -71.5) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[3] <= -63.0) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }

                            else {
                                if (x[0] <= -91.5) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[21] <= -44.5) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }
                        }

                        // tree #46
                        if (x[3] <= -72.0) {
                            if (x[16] <= -38.5) {
                                if (x[8] <= -79.5) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[2] += 1;
                                }
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        else {
                            if (x[10] <= -60.5) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[23] <= -79.0) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[21] <= -44.5) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        if (x[10] <= -24.0) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[0] <= -91.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #47
                        if (x[23] <= -79.0) {
                            if (x[18] <= -43.0) {
                                votes[2] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        else {
                            if (x[2] <= -74.0) {
                                votes[2] += 1;
                            }

                            else {
                                if (x[1] <= -68.0) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[13] <= -41.0) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        if (x[17] <= -87.5) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            if (x[20] <= -45.0) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                if (x[6] <= -44.5) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #48
                        if (x[6] <= -41.5) {
                            votes[0] += 1;
                        }

                        else {
                            if (x[4] <= -55.5) {
                                if (x[18] <= -40.0) {
                                    votes[2] += 1;
                                }

                                else {
                                    if (x[4] <= -58.5) {
                                        if (x[13] <= -42.5) {
                                            votes[2] += 1;
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }

                            else {
                                if (x[20] <= -88.5) {
                                    if (x[1] <= -31.0) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        // tree #49
                        if (x[10] <= -71.0) {
                            if (x[17] <= -38.5) {
                                votes[2] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        else {
                            if (x[9] <= -85.0) {
                                if (x[24] <= -79.5) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }

                            else {
                                if (x[0] <= -87.5) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[3] <= -65.0) {
                                        if (x[11] <= -83.0) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }

                                    else {
                                        if (x[11] <= -39.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[17] <= -44.0) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #50
                        if (x[2] <= -74.5) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[10] <= -58.5) {
                                if (x[17] <= -130.5) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[4] <= -59.5) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }

                            else {
                                if (x[17] <= -43.0) {
                                    if (x[16] <= -86.5) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    if (x[25] <= -93.0) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        if (x[22] <= -45.0) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[23] <= -32.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #51
                        if (x[4] <= -56.5) {
                            if (x[18] <= -40.0) {
                                votes[2] += 1;
                            }

                            else {
                                if (x[12] <= -42.5) {
                                    if (x[9] <= -77.5) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }
                        }

                        else {
                            if (x[3] <= -33.0) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[17] <= -85.5) {
                                    if (x[9] <= -45.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    if (x[20] <= -45.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[9] <= -43.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                }
                            }
                        }

                        // tree #52
                        if (x[18] <= -40.0) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[12] <= -41.0) {
                                if (x[7] <= -82.0) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                if (x[24] <= -78.5) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[15] <= -39.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[24] <= -33.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[0] <= -90.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #53
                        if (x[16] <= -38.5) {
                            if (x[11] <= -72.5) {
                                if (x[8] <= -40.0) {
                                    if (x[20] <= -89.5) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }

                            else {
                                if (x[11] <= -32.0) {
                                    votes[2] += 1;
                                }

                                else {
                                    if (x[9] <= -45.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                        }

                        else {
                            if (x[9] <= -83.5) {
                                votes[0] += 1;
                            }

                            else {
                                if (x[9] <= -36.0) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[0] <= -91.0) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        if (x[25] <= -44.5) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }
                                }
                            }
                        }

                        // tree #54
                        if (x[23] <= -78.0) {
                            if (x[18] <= -43.0) {
                                votes[2] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        else {
                            if (x[19] <= -40.0) {
                                votes[2] += 1;
                            }

                            else {
                                if (x[3] <= -72.0) {
                                    if (x[2] <= -75.5) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    if (x[10] <= -24.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[0] <= -90.5) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }
                                }
                            }
                        }

                        // tree #55
                        if (x[3] <= -73.0) {
                            if (x[4] <= -56.0) {
                                votes[2] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        else {
                            if (x[11] <= -82.5) {
                                if (x[23] <= -81.5) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }

                            else {
                                if (x[23] <= -78.0) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[6] <= -42.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[23] <= -33.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[17] <= -43.0) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                if (x[20] <= -46.0) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #56
                        if (x[10] <= -71.0) {
                            if (x[18] <= -40.0) {
                                votes[2] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        else {
                            if (x[23] <= -78.0) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[21] <= -43.5) {
                                    if (x[0] <= -87.5) {
                                        if (x[13] <= -41.0) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    if (x[14] <= -39.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[0] <= -91.0) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }
                                }
                            }
                        }

                        // tree #57
                        if (x[18] <= -40.0) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[1] <= -70.5) {
                                if (x[10] <= -63.0) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }

                            else {
                                if (x[5] <= -43.0) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[8] <= -74.5) {
                                        if (x[1] <= -28.5) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }

                                    else {
                                        if (x[7] <= -43.0) {
                                            votes[2] += 1;
                                        }

                                        else {
                                            if (x[4] <= -33.0) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                if (x[22] <= -46.0) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #58
                        if (x[19] <= -40.0) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[12] <= -41.0) {
                                if (x[23] <= -40.5) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[12] <= -84.5) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }

                            else {
                                if (x[10] <= -58.0) {
                                    if (x[22] <= -139.5) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }
                        }

                        // tree #59
                        if (x[4] <= -56.0) {
                            if (x[23] <= -31.5) {
                                if (x[23] <= -79.0) {
                                    if (x[23] <= -87.0) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }

                            else {
                                votes[2] += 1;
                            }
                        }

                        else {
                            if (x[6] <= -43.0) {
                                votes[0] += 1;
                            }

                            else {
                                if (x[11] <= -87.5) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[14] <= -87.5) {
                                        if (x[7] <= -37.0) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                        }

                        // tree #60
                        if (x[19] <= -40.0) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[1] <= -70.5) {
                                votes[0] += 1;
                            }

                            else {
                                if (x[20] <= -86.5) {
                                    if (x[23] <= -76.0) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }

                                else {
                                    if (x[7] <= -82.0) {
                                        if (x[4] <= -52.5) {
                                            votes[2] += 1;
                                        }

                                        else {
                                            if (x[21] <= -45.0) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                        }

                        // tree #61
                        if (x[3] <= -66.5) {
                            if (x[24] <= -76.5) {
                                if (x[19] <= -42.5) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                if (x[4] <= -56.5) {
                                    if (x[8] <= -33.0) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        else {
                            if (x[0] <= -90.0) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[9] <= -79.5) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[10] <= -62.0) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        if (x[11] <= -40.0) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[25] <= -44.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #62
                        if (x[10] <= -70.5) {
                            if (x[2] <= -73.0) {
                                votes[2] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        else {
                            if (x[10] <= -57.5) {
                                if (x[6] <= -87.0) {
                                    votes[0] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                if (x[13] <= -42.5) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[9] <= -42.5) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[25] <= -47.0) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            if (x[0] <= -90.0) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #63
                        if (x[10] <= -71.0) {
                            if (x[17] <= -39.0) {
                                votes[2] += 1;
                            }

                            else {
                                if (x[13] <= -42.5) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[2] += 1;
                                }
                            }
                        }

                        else {
                            if (x[4] <= -58.5) {
                                votes[0] += 1;
                            }

                            else {
                                if (x[4] <= -23.0) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[20] <= -44.5) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[6] <= -44.0) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[7] <= -45.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #64
                        if (x[18] <= -40.0) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[3] <= -66.5) {
                                if (x[4] <= -58.5) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                if (x[13] <= -43.5) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }
                        }

                        // tree #65
                        if (x[6] <= -41.5) {
                            votes[0] += 1;
                        }

                        else {
                            if (x[3] <= -73.0) {
                                if (x[23] <= -41.5) {
                                    if (x[10] <= -72.5) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    votes[2] += 1;
                                }
                            }

                            else {
                                if (x[11] <= -78.5) {
                                    if (x[12] <= -43.5) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }

                                else {
                                    if (x[22] <= -90.5) {
                                        if (x[4] <= -23.0) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                        }

                        // tree #66
                        if (x[3] <= -76.5) {
                            if (x[16] <= -87.5) {
                                votes[1] += 1;
                            }

                            else {
                                votes[2] += 1;
                            }
                        }

                        else {
                            if (x[24] <= -78.0) {
                                if (x[13] <= -88.5) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                if (x[0] <= -91.0) {
                                    if (x[4] <= -30.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    if (x[3] <= -67.5) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }
                        }

                        // tree #67
                        if (x[5] <= -41.5) {
                            votes[0] += 1;
                        }

                        else {
                            if (x[22] <= -44.0) {
                                if (x[3] <= -63.5) {
                                    if (x[2] <= -76.0) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }

                            else {
                                if (x[2] <= -74.5) {
                                    votes[2] += 1;
                                }

                                else {
                                    if (x[11] <= -78.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[20] <= -89.0) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                }
                            }
                        }

                        // tree #68
                        if (x[19] <= -40.0) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[6] <= -42.5) {
                                votes[0] += 1;
                            }

                            else {
                                if (x[10] <= -58.5) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[23] <= -31.5) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[7] <= -45.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                }
                            }
                        }

                        // tree #69
                        if (x[10] <= -71.0) {
                            if (x[2] <= -72.0) {
                                votes[2] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        else {
                            if (x[24] <= -78.5) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[25] <= -43.5) {
                                    if (x[14] <= -40.5) {
                                        if (x[3] <= -68.0) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    if (x[10] <= -60.5) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }
                        }

                        // tree #70
                        if (x[19] <= -40.0) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[3] <= -66.5) {
                                if (x[22] <= -44.0) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[21] <= -90.5) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }

                            else {
                                if (x[9] <= -85.5) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[14] <= -40.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                        }

                        // tree #71
                        if (x[18] <= -40.0) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[13] <= -41.0) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[10] <= -58.5) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[10] <= -23.5) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[0] <= -91.5) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            if (x[25] <= -44.5) {
                                                if (x[14] <= -42.0) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #72
                        if (x[2] <= -73.5) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[3] <= -66.5) {
                                if (x[0] <= -93.0) {
                                    votes[0] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                if (x[11] <= -39.5) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[0] <= -90.0) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }
                        }

                        // tree #73
                        if (x[19] <= -40.0) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[10] <= -58.0) {
                                if (x[2] <= -77.0) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                if (x[9] <= -42.0) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[10] <= -25.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[0] <= -45.5) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            if (x[7] <= -45.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #74
                        if (x[10] <= -71.0) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[6] <= -41.5) {
                                votes[0] += 1;
                            }

                            else {
                                if (x[11] <= -81.5) {
                                    if (x[15] <= -86.0) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }

                                else {
                                    if (x[4] <= -58.5) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[20] <= -88.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                }
                            }
                        }

                        // tree #75
                        if (x[19] <= -40.0) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[3] <= -66.5) {
                                if (x[10] <= -56.0) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }

                            else {
                                if (x[13] <= -42.5) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[24] <= -30.5) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[14] <= -40.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[0] <= -92.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                if (x[17] <= -87.0) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    votes[0] += 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #76
                        if (x[2] <= -74.5) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[3] <= -66.5) {
                                if (x[8] <= -73.5) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[10] <= -65.5) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }

                            else {
                                if (x[1] <= -65.5) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[23] <= -76.5) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        if (x[9] <= -45.0) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[24] <= -34.0) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                if (x[20] <= -44.5) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    if (x[0] <= -47.5) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        votes[0] += 1;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #77
                        if (x[4] <= -58.5) {
                            if (x[19] <= -40.5) {
                                votes[2] += 1;
                            }

                            else {
                                if (x[2] <= -77.0) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }
                        }

                        else {
                            if (x[2] <= -75.5) {
                                votes[2] += 1;
                            }

                            else {
                                if (x[2] <= -32.5) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[5] <= -42.5) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[22] <= -44.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[25] <= -44.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                if (x[20] <= -46.0) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #78
                        if (x[2] <= -73.5) {
                            if (x[8] <= -82.0) {
                                if (x[8] <= -85.5) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                votes[2] += 1;
                            }
                        }

                        else {
                            if (x[4] <= -58.5) {
                                votes[0] += 1;
                            }

                            else {
                                if (x[9] <= -89.5) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[1] <= -73.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[20] <= -40.5) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            if (x[0] <= -47.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                if (x[9] <= -37.5) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    if (x[17] <= -44.0) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        votes[0] += 1;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #79
                        if (x[4] <= -55.5) {
                            if (x[3] <= -71.5) {
                                votes[2] += 1;
                            }

                            else {
                                votes[0] += 1;
                            }
                        }

                        else {
                            if (x[6] <= -42.0) {
                                votes[0] += 1;
                            }

                            else {
                                if (x[12] <= -41.0) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[2] <= -33.5) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        if (x[25] <= -44.5) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            if (x[0] <= -90.0) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #80
                        if (x[3] <= -65.0) {
                            if (x[2] <= -74.5) {
                                votes[2] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        else {
                            if (x[23] <= -31.5) {
                                votes[0] += 1;
                            }

                            else {
                                if (x[20] <= -44.5) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[0] <= -47.5) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }
                        }

                        // tree #81
                        if (x[19] <= -40.0) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[1] <= -70.5) {
                                if (x[9] <= -82.0) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[9] <= -40.0) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }

                            else {
                                if (x[10] <= -29.5) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[17] <= -43.0) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }
                        }

                        // tree #82
                        if (x[2] <= -74.0) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[23] <= -78.0) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[23] <= -31.5) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[13] <= -41.0) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        if (x[9] <= -43.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[7] <= -45.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                if (x[15] <= -44.5) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #83
                        if (x[12] <= -42.0) {
                            if (x[19] <= -40.0) {
                                votes[2] += 1;
                            }

                            else {
                                if (x[4] <= -58.5) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        else {
                            if (x[3] <= -66.5) {
                                if (x[10] <= -77.5) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                if (x[5] <= -41.5) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[25] <= -92.5) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        if (x[2] <= -30.0) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[9] <= -45.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                if (x[22] <= -46.5) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    if (x[0] <= -47.5) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        votes[0] += 1;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #84
                        if (x[2] <= -74.0) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[2] <= -64.5) {
                                if (x[24] <= -78.5) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[24] <= -33.5) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[7] <= -34.5) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[14] <= -40.0) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[9] <= -42.5) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[23] <= -33.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[22] <= -46.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #85
                        if (x[10] <= -70.5) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[10] <= -58.5) {
                                if (x[8] <= -38.5) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }

                            else {
                                if (x[15] <= -40.5) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[4] <= -29.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[5] <= -43.0) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                }
                            }
                        }

                        // tree #86
                        if (x[18] <= -40.0) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[23] <= -79.0) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[1] <= -67.5) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[20] <= -86.5) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[4] <= -56.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[13] <= -41.0) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                if (x[7] <= -44.0) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #87
                        if (x[18] <= -40.0) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[12] <= -41.0) {
                                if (x[7] <= -82.0) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                if (x[3] <= -66.5) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[25] <= -93.5) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        if (x[11] <= -40.0) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[2] <= -34.0) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                if (x[20] <= -44.5) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    if (x[6] <= -44.5) {
                                                        votes[0] += 1;
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #88
                        if (x[12] <= -41.0) {
                            if (x[4] <= -55.5) {
                                votes[2] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        else {
                            if (x[3] <= -69.5) {
                                if (x[2] <= -77.0) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                if (x[4] <= -57.5) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[5] <= -42.5) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[11] <= -82.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[0] <= -46.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                if (x[1] <= -30.0) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    if (x[20] <= -46.0) {
                                                        votes[0] += 1;
                                                    }

                                                    else {
                                                        if (x[21] <= -44.5) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            votes[0] += 1;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #89
                        if (x[10] <= -58.0) {
                            if (x[8] <= -78.5) {
                                if (x[18] <= -43.0) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                if (x[4] <= -52.5) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        else {
                            if (x[17] <= -87.5) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[0] <= -92.0) {
                                    if (x[10] <= -26.5) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }
                        }

                        // tree #90
                        if (x[19] <= -40.0) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[1] <= -70.5) {
                                if (x[13] <= -42.5) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }

                            else {
                                if (x[20] <= -90.5) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[3] <= -63.0) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        if (x[23] <= -33.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[9] <= -45.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #91
                        if (x[10] <= -70.5) {
                            if (x[19] <= -40.0) {
                                votes[2] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        else {
                            if (x[1] <= -70.5) {
                                votes[0] += 1;
                            }

                            else {
                                if (x[1] <= -28.5) {
                                    if (x[6] <= -43.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    if (x[20] <= -86.5) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[22] <= -91.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                }
                            }
                        }

                        // tree #92
                        if (x[10] <= -71.0) {
                            if (x[3] <= -72.0) {
                                votes[2] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        else {
                            if (x[4] <= -58.5) {
                                votes[0] += 1;
                            }

                            else {
                                if (x[10] <= -58.5) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[15] <= -40.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[20] <= -45.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[4] <= -29.0) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #93
                        if (x[18] <= -40.0) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[10] <= -58.5) {
                                if (x[9] <= -133.5) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[2] <= -77.0) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }

                            else {
                                if (x[13] <= -42.5) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[0] <= -91.5) {
                                        if (x[24] <= -35.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }
                        }

                        // tree #94
                        if (x[19] <= -40.0) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[20] <= -88.5) {
                                votes[0] += 1;
                            }

                            else {
                                if (x[3] <= -65.5) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[2] <= -30.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[20] <= -43.0) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            if (x[22] <= -45.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #95
                        if (x[18] <= -40.0) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[4] <= -58.5) {
                                if (x[12] <= -42.5) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }

                            else {
                                if (x[2] <= -32.5) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[6] <= -42.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[7] <= -45.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[13] <= -42.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                if (x[14] <= -44.0) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    if (x[0] <= -47.5) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        votes[0] += 1;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #96
                        if (x[10] <= -58.5) {
                            if (x[2] <= -74.5) {
                                votes[2] += 1;
                            }

                            else {
                                if (x[20] <= -135.5) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[18] <= -40.0) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                        }

                        else {
                            if (x[1] <= -35.0) {
                                votes[0] += 1;
                            }

                            else {
                                if (x[9] <= -44.0) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[22] <= -91.5) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[0] <= -45.5) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }
                                }
                            }
                        }

                        // tree #97
                        if (x[19] <= -40.0) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[8] <= -35.0) {
                                if (x[10] <= -57.5) {
                                    if (x[3] <= -77.5) {
                                        if (x[22] <= -46.5) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[2] += 1;
                                        }
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }

                            else {
                                if (x[0] <= -94.5) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[10] <= -25.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[14] <= -44.0) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[20] <= -46.0) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                if (x[0] <= -46.5) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    votes[0] += 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #98
                        if (x[19] <= -40.0) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[12] <= -41.0) {
                                if (x[10] <= -76.5) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                if (x[24] <= -77.5) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[17] <= -87.5) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        if (x[9] <= -80.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[0] <= -88.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                if (x[7] <= -70.5) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #99
                        if (x[3] <= -72.0) {
                            if (x[4] <= -53.5) {
                                votes[2] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        else {
                            if (x[12] <= -42.5) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[23] <= -79.0) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[15] <= -39.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[24] <= -33.0) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[17] <= -44.0) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                if (x[20] <= -45.0) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    if (x[6] <= -44.5) {
                                                        votes[0] += 1;
                                                    }

                                                    else {
                                                        if (x[7] <= -45.5) {
                                                            votes[0] += 1;
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #100
                        if (x[1] <= -65.5) {
                            if (x[18] <= -40.0) {
                                votes[2] += 1;
                            }

                            else {
                                if (x[24] <= -79.5) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }
                        }

                        else {
                            if (x[20] <= -88.5) {
                                if (x[8] <= -84.5) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[2] <= -33.5) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }

                            else {
                                if (x[6] <= -43.5) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[18] <= -41.0) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        if (x[4] <= -62.0) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                }
                            }
                        }

                        // return argmax of votes
                        uint8_t classIdx = 0;
                        float maxVotes = votes[0];

                        for (uint8_t i = 1; i < 3; i++) {
                            if (votes[i] > maxVotes) {
                                classIdx = i;
                                maxVotes = votes[i];
                            }
                        }

                        return classIdx;
                    }

                    /**
                    * Predict readable class name
                    */
                    const char* predictLabel(float *x) {
                        return idxToLabel(predict(x));
                    }

                    /**
                    * Convert class idx to readable name
                    */
                    const char* idxToLabel(uint8_t classIdx) {
                        switch (classIdx) {
                            case 0:
                            return "Praticas didaticas";
                            case 1:
                            return "Pesquisa engenharia";
                            case 2:
                            return "Fibras oticas";
                            default:
                            return "Houston we have a problem";
                        }
                    }

                protected:
                };
            }
        }
    }