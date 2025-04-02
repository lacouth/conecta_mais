#pragma once
#include <cstdarg>
namespace Eloquent {
    namespace ML {
        namespace Port {
            class DecisionTree {
                public:
                    /**
                    * Predict class for features vector
                    */
                    int predict(float *x) {
                        if (x[2] <= -73.5) {
                            if (x[4] <= -56.0) {
                                return 2;
                            }

                            else {
                                return 1;
                            }
                        }

                        else {
                            if (x[10] <= -58.5) {
                                if (x[8] <= -37.5) {
                                    return 1;
                                }

                                else {
                                    return 0;
                                }
                            }

                            else {
                                if (x[0] <= -90.5) {
                                    if (x[24] <= -31.5) {
                                        return 0;
                                    }

                                    else {
                                        return 1;
                                    }
                                }

                                else {
                                    if (x[17] <= -87.5) {
                                        return 1;
                                    }

                                    else {
                                        return 0;
                                    }
                                }
                            }
                        }
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