#pragma once
#include "ICommand.hpp"

namespace Command
{
    class IRelayCommand :
        public ICommand
    {
    protected:
        IRelayCommand() {};
        virtual ~IRelayCommand() {};

    public:
        /// <summary>
        /// Notifies that the <see cref="ICommand.CanExecute"/> property has changed.
        /// </summary>
        virtual void notifyCanExecuteChanged() = 0;
    };
}
