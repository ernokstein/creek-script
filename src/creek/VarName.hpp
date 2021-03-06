#pragma once

#include <cstdint>
#include <map>
#include <string>
#include <vector>

#include <creek/api_mode.hpp>


namespace creek
{
    /// Variable name.
    class CREEK_API VarName
    {
    public:
        /// Type used for the name.
        using Name = std::string;

        /// Type used for the id.
        using Id = uintptr_t;


        /// @brief  `VarName` constructor.
        VarName();

        /// @brief  `VarName` constructor.
        /// @param  name    Name of the variable.
        VarName(const std::string& name);

        /// @brief  `VarName` constructor.
        /// @param  name    Name of the variable.
        VarName(const char* name);

        /// @brief  `VarName` copy constructor.
        VarName(const VarName& other);

        /// @brief  `VarName` move constructor.
        VarName(VarName&& other);

        /// @brief  Assignment.
        VarName& operator = (const VarName& other);


        /// Get a `VarName` from an id.
        /// If the id is not register, throws an exception.
        static VarName from_id(Id id);

        /// Get a `VarName` from a name.
        /// If the name is not register, creates a new VarName.
        static VarName from_name(const std::string& name);


        /// Get the id.
        Id id() const;

        /// Get the name.
        const Name& name() const;


        /// @name   Relational operators
        /// @{
        bool operator == (const VarName& other) const;
        bool operator != (const VarName& other) const;
        bool operator <  (const VarName& other) const;
        bool operator <= (const VarName& other) const;
        bool operator >  (const VarName& other) const;
        bool operator >= (const VarName& other) const;
        /// @}


    private:
        explicit VarName(Id id);

        static std::map<Name, Id> s_ids;
        static std::vector<Name> s_names;

        Id m_id;
    };
}
