#pragma once
#include "IRelayCommand.hpp"

namespace Command
{
    template <typename T>
    class IRelayCommandT :
        public IRelayCommand
    {
    protected:
        IRelayCommandT() {};
        virtual ~IRelayCommandT() {};

    public:
        /// <summary>
        /// Provides a strongly-typed variant of <see cref="ICommand.CanExecute(object)"
        /// </summary>
        /// <param name="parameter"></param>
        /// <returns></returns>
        virtual const bool canExecute(T parameter) = 0;

        /// <summary>
        /// Provides a strongly-typed variant of <see cref="ICommand.Execute(object)"
        /// </summary>
        virtual void execute(T parameter) = 0;
    };
}