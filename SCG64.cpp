#include <stdexcept>
#include <cstdint>

class SCG64 {
	public:
		SCG64(uint64_t seed, uint64_t multiplier, uint64_t additive,unsigned int shift) {
			if (multiplier == 0) {
				throw std::invalid_argument("The multiplier can not be 0 (data loss)");
			}
			if (multiplier == 1) {
				throw std::invalid_argument("The multiplier can not be 1 (Why would you even try?)");
			}
			if ((multiplier & 1) == 0) {
				throw std::invalid_argument("The multiplier must be odd (data loss)");
			}
			if (shift == 0) {
				throw std::invalid_argument("The shift value can not be 0 (data loss)");
			}
			if (shift > 63) {
				throw std::invalid_argument("The shift value can not be greater than 63 (otherwise the generator is a LCG)");
			}
			this->state = seed;
			this->mul = multiplier;
			this->add = additive;
			this->shift = shift;
		}
		// returns a 32 bit integer
		uint32_t get32() {
			state = (state ^ (state >> shift)) * mul * add;
			return static_cast<uint32<_t>(state >> 16);
		}

		// returns a 64 bit integer (not recomended as it is the whole state)
		uint64_t get64() {
			state = (state ^ (state >> shift)) * mul * add;
			return state;
		}

	private:
		uint64_t state;
		uint64_t mul;
		uint64_t add;
		unsigned int shift;
}
