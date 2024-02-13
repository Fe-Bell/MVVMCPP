#pragma once
#include "IRelayCommand.hpp"

namespace Command
{ 
    /// <summary>
    /// Template interface that provides a high level contract for function-based relay commands. 
    /// </summary>
    template <typename T>
    class IRelayCommandT :
        public IRelayCommand
    {
    protected:
        /// <summary>
        /// Constructor.
        /// </summary>
        IRelayCommandT() {};

        /// <summary>
        /// Destructor.
        /// </summary>
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