/*
** EPITECH PROJECT, 2020
** WarpSystem
** File description:
** WarpSystem
*/

#ifndef WARPSYSTEM
#define WARPSYSTEM

namespace WarpSystem {
    class QuantumReactor {
    	public:
            QuantumReactor();
            ~QuantumReactor();
            bool isStable();
            void setStability(bool);

        private:
            bool _stability;
    };

    class Core {
    	public:
            Core(WarpSystem::QuantumReactor *);
            ~Core();
            WarpSystem::QuantumReactor *checkReactor(void);

        private:
            WarpSystem::QuantumReactor *_coreReactor;
    };
};

#endif /* !WARPSYSTEM */
