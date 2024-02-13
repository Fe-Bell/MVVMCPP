#pragma once
#include "ICommand.hpp"

namespace Command
{
    /// <summary>
    /// Interface that provides a high level contract for function-based relay commands. 
    /// </summary>
    class IRelayCommand :
        public ICommand
    {
    protected:
        /// <summary>
        /// Constructor.
        /// </summary>
        IRelayCommand() {};

        /// <summary>
        /// Destructor.
        /// </summary>
        virtual ~IRelayCommand() {};

        /// <summary>
        /// Notifies that the <see cref="ICommand.CanExecute"/> property has changed.
        /// </summary>
        virtual void notifyCanExecuteChanged() = 0;
    };
}
