#include "windows.h"
#include "wine/asm.h"
#include "wine/debug.h"
WINE_DEFAULT_DEBUG_CHANNEL(thunks);

enum _EVENT_TYPE;
enum _TIMER_TYPE;
enum _WAIT_TYPE;
struct _STRING;
struct _UNICODE_STRING;
struct _RTL_SYSTEM_TIME;
struct _RTL_TIME_ZONE_INFORMATION;
struct _RTL_TIME_DYNAMIC_ZONE_INFORMATION;
struct _CLIENT_ID;
struct _CURDIR;
struct RTL_DRIVE_LETTER_CURDIR;
struct _RTL_RELATIVE_NAME;
struct tagRTL_BITMAP;
struct tagRTL_BITMAP_RUN;
struct _RTL_USER_PROCESS_PARAMETERS;
struct _PEB_LDR_DATA;
struct _GDI_TEB_BATCH;
struct _RTL_ACTIVATION_CONTEXT_STACK_FRAME;
struct _ACTIVATION_CONTEXT_STACK;
struct _TEB_ACTIVE_FRAME_CONTEXT;
struct _TEB_ACTIVE_FRAME_CONTEXT_EX;
struct _TEB_ACTIVE_FRAME;
struct _TEB_ACTIVE_FRAME_EX;
struct _PEB;
struct _TEB;
enum _FILE_INFORMATION_CLASS;
struct _FILE_DIRECTORY_INFORMATION;
struct _FILE_FULL_DIRECTORY_INFORMATION;
struct _FILE_ID_FULL_DIRECTORY_INFORMATION;
struct _FILE_BOTH_DIRECTORY_INFORMATION;
struct _FILE_ID_BOTH_DIRECTORY_INFORMATION;
struct _FILE_ID_GLOBAL_TX_DIR_INFORMATION;
struct _FILE_BASIC_INFORMATION;
struct _FILE_STANDARD_INFORMATION;
struct _FILE_INTERNAL_INFORMATION;
struct _FILE_ID_128;
struct _FILE_ID_INFORMATION;
struct _FILE_EA_INFORMATION;
struct _FILE_ACCESS_INFORMATION;
struct _FILE_NAME_INFORMATION;
struct _FILE_RENAME_INFORMATION;
struct _FILE_LINK_INFORMATION;
struct _FILE_NAMES_INFORMATION;
struct _FILE_DISPOSITION_INFORMATION;
struct _FILE_POSITION_INFORMATION;
struct _FILE_ALIGNMENT_INFORMATION;
struct _FILE_ALLOCATION_INFORMATION;
struct _FILE_END_OF_FILE_INFORMATION;
struct _FILE_NETWORK_OPEN_INFORMATION;
struct _FILE_FULL_EA_INFORMATION;
struct _FILE_MODE_INFORMATION;
struct _FILE_STREAM_INFORMATION;
struct _FILE_ATTRIBUTE_TAG_INFORMATION;
struct _FILE_MAILSLOT_QUERY_INFORMATION;
struct _FILE_MAILSLOT_SET_INFORMATION;
struct _FILE_PIPE_INFORMATION;
struct _FILE_PIPE_LOCAL_INFORMATION;
struct _FILE_OBJECTID_INFORMATION;
struct _FILE_QUOTA_INFORMATION;
struct _FILE_REPARSE_POINT_INFORMATION;
struct _FILE_ALL_INFORMATION;
struct _FILE_IO_COMPLETION_NOTIFICATION_INFORMATION;
enum _FSINFOCLASS;
enum _KEY_INFORMATION_CLASS;
enum _KEY_VALUE_INFORMATION_CLASS;
enum _OBJECT_INFORMATION_CLASS;
enum _PROCESSINFOCLASS;
enum _SECTION_INHERIT;
enum _SYSTEM_INFORMATION_CLASS;
enum _THREADINFOCLASS;
struct _THREAD_BASIC_INFORMATION;
struct _THREAD_DESCRIPTOR_INFORMATION;
struct _KERNEL_USER_TIMES;
enum _WINSTATIONINFOCLASS;
enum _MEMORY_INFORMATION_CLASS;
struct _MEMORY_SECTION_NAME;
enum _MUTANT_INFORMATION_CLASS;
struct _MUTANT_BASIC_INFORMATION;
enum _TIMER_INFORMATION_CLASS;
struct _TIMER_BASIC_INFORMATION;
enum DOS_PATHNAME_TYPE;
struct _SYSTEM_THREAD_INFORMATION;
struct _IO_STATUS_BLOCK;
struct _KEY_BASIC_INFORMATION;
struct _KEY_NODE_INFORMATION;
struct _KEY_FULL_INFORMATION;
struct _KEY_NAME_INFORMATION;
struct _KEY_CACHED_INFORMATION;
struct _KEY_VALUE_ENTRY;
struct _KEY_VALUE_BASIC_INFORMATION;
struct _KEY_VALUE_FULL_INFORMATION;
struct _KEY_VALUE_PARTIAL_INFORMATION;
struct _OBJECT_ATTRIBUTES;
struct _OBJECT_DATA_INFORMATION;
struct _OBJECT_BASIC_INFORMATION;
struct _OBJECT_NAME_INFORMATION;
struct __OBJECT_TYPE_INFORMATION;
struct _PROCESS_BASIC_INFORMATION;
struct _PROCESS_PRIORITY_CLASS;
struct _RTL_HEAP_DEFINITION;
struct _RTL_RWLOCK;
struct _SYSTEM_BASIC_INFORMATION;
struct _SYSTEM_CPU_INFORMATION;
struct _SYSTEM_PERFORMANCE_INFORMATION;
struct _SYSTEM_TIMEOFDAY_INFORMATION;
struct _SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION;
struct _SYSTEM_DRIVER_INFORMATION;
struct _SYSTEM_HANDLE_ENTRY;
struct _SYSTEM_HANDLE_INFORMATION;
struct _SYSTEM_CACHE_INFORMATION;
struct _SYSTEM_INTERRUPT_INFORMATION;
struct _SYSTEM_CONFIGURATION_INFO;
struct _SYSTEM_EXCEPTION_INFORMATION;
struct _SYSTEM_LOOKASIDE_INFORMATION;
struct _SYSTEM_KERNEL_DEBUGGER_INFORMATION;
struct _VM_COUNTERS_;
struct _SYSTEM_PROCESS_INFORMATION;
struct _SYSTEM_REGISTRY_QUOTA_INFORMATION;
struct _SYSTEM_TIME_ADJUSTMENT;
enum _SYSTEM_FIRMWARE_TABLE_ACTION;
struct _SYSTEM_FIRMWARE_TABLE_INFORMATION;
struct _TIME_FIELDS;
struct _WINSTATIONINFORMATIONW;
struct _LDR_RESOURCE_INFO;
struct _DEBUG_BUFFER;
struct _DEBUG_MODULE_INFORMATION;
struct _DEBUG_HEAP_INFORMATION;
struct _DEBUG_LOCK_INFORMATION;
struct _PORT_MESSAGE_HEADER;
enum _ATOM_INFORMATION_CLASS;
struct _ATOM_BASIC_INFORMATION;
struct _RTL_HANDLE;
struct _RTL_HANDLE_TABLE;
struct _RTL_QUERY_REGISTRY_TABLE;
struct _KEY_MULTIPLE_VALUE_INFORMATION;
enum _EVENT_INFORMATION_CLASS;
struct _EVENT_BASIC_INFORMATION;
enum _SEMAPHORE_INFORMATION_CLASS;
struct _SEMAPHORE_BASIC_INFORMATION;
enum _SECTION_INFORMATION_CLASS;
struct _SECTION_BASIC_INFORMATION;
struct _SECTION_IMAGE_INFORMATION;
struct _LPC_SECTION_WRITE;
struct _LPC_SECTION_READ;
struct _LPC_MESSAGE;
struct _RTL_USER_PROCESS_INFORMATION;
enum _SHUTDOWN_ACTION;
struct _COUNTED_REASON_CONTEXT;
enum _KPROFILE_SOURCE;
struct _DIRECTORY_BASIC_INFORMATION;
struct _INITIAL_TEB;
enum _PORT_INFORMATION_CLASS;
enum _IO_COMPLETION_INFORMATION_CLASS;
struct _FILE_COMPLETION_INFORMATION;
struct _FILE_IO_COMPLETION_INFORMATION;
enum _HARDERROR_RESPONSE_OPTION;
enum _HARDERROR_RESPONSE;
enum _SYSDBG_COMMAND;
struct _LDR_MODULE;
struct _LDR_DLL_LOADED_NOTIFICATION_DATA;
struct _LDR_DLL_UNLOADED_NOTIFICATION_DATA;
union _LDR_DLL_NOTIFICATION_DATA;
struct _SYSTEM_MODULE;
struct _SYSTEM_MODULE_INFORMATION;
struct WIN16_SUBSYSTEM_TIB;
struct request_header;
struct reply_header;
struct request_max_size;
union debug_event_t;
enum cpu_type;
struct context_t;
struct send_fd;
struct wake_up_reply;
struct startup_info_t;
struct property_data_t;
struct rectangle_t;
struct async_data_t;
struct hw_msg_source;
struct hardware_msg_data;
struct callback_msg_data;
struct winevent_msg_data;
union hw_input_t;
union message_data_t;
struct char_info_t;
struct filesystem_event;
struct luid_t;
struct security_descriptor;
struct object_attributes;
struct token_groups;
enum select_op;
union select_op_t;
enum apc_type;
union apc_call_t;
union apc_result_t;
enum irp_type;
union irp_params_t;
struct pe_image_info_t;
struct rawinput_device;
struct new_process_request;
struct new_process_reply;
struct exec_process_request;
struct exec_process_reply;
struct get_new_process_info_request;
struct get_new_process_info_reply;
struct new_thread_request;
struct new_thread_reply;
struct get_startup_info_request;
struct get_startup_info_reply;
struct init_process_done_request;
struct init_process_done_reply;
struct init_thread_request;
struct init_thread_reply;
struct terminate_process_request;
struct terminate_process_reply;
struct terminate_thread_request;
struct terminate_thread_reply;
struct get_process_info_request;
struct get_process_info_reply;
struct get_process_vm_counters_request;
struct get_process_vm_counters_reply;
struct set_process_info_request;
struct set_process_info_reply;
struct get_thread_info_request;
struct get_thread_info_reply;
struct get_thread_times_request;
struct get_thread_times_reply;
struct set_thread_info_request;
struct set_thread_info_reply;
struct get_dll_info_request;
struct get_dll_info_reply;
struct suspend_thread_request;
struct suspend_thread_reply;
struct resume_thread_request;
struct resume_thread_reply;
struct load_dll_request;
struct load_dll_reply;
struct unload_dll_request;
struct unload_dll_reply;
struct queue_apc_request;
struct queue_apc_reply;
struct get_apc_result_request;
struct get_apc_result_reply;
struct close_handle_request;
struct close_handle_reply;
struct set_handle_info_request;
struct set_handle_info_reply;
struct dup_handle_request;
struct dup_handle_reply;
struct open_process_request;
struct open_process_reply;
struct open_thread_request;
struct open_thread_reply;
struct select_request;
struct select_reply;
struct create_event_request;
struct create_event_reply;
struct event_op_request;
struct event_op_reply;
enum event_op;
struct query_event_request;
struct query_event_reply;
struct open_event_request;
struct open_event_reply;
struct create_keyed_event_request;
struct create_keyed_event_reply;
struct open_keyed_event_request;
struct open_keyed_event_reply;
struct create_mutex_request;
struct create_mutex_reply;
struct release_mutex_request;
struct release_mutex_reply;
struct open_mutex_request;
struct open_mutex_reply;
struct query_mutex_request;
struct query_mutex_reply;
struct create_semaphore_request;
struct create_semaphore_reply;
struct release_semaphore_request;
struct release_semaphore_reply;
struct query_semaphore_request;
struct query_semaphore_reply;
struct open_semaphore_request;
struct open_semaphore_reply;
struct create_file_request;
struct create_file_reply;
struct open_file_object_request;
struct open_file_object_reply;
struct alloc_file_handle_request;
struct alloc_file_handle_reply;
struct get_handle_unix_name_request;
struct get_handle_unix_name_reply;
struct get_handle_fd_request;
struct get_handle_fd_reply;
enum server_fd_type;
struct get_directory_cache_entry_request;
struct get_directory_cache_entry_reply;
struct flush_request;
struct flush_reply;
struct get_file_info_request;
struct get_file_info_reply;
struct get_volume_info_request;
struct get_volume_info_reply;
struct lock_file_request;
struct lock_file_reply;
struct unlock_file_request;
struct unlock_file_reply;
struct create_socket_request;
struct create_socket_reply;
struct accept_socket_request;
struct accept_socket_reply;
struct accept_into_socket_request;
struct accept_into_socket_reply;
struct set_socket_event_request;
struct set_socket_event_reply;
struct get_socket_event_request;
struct get_socket_event_reply;
struct get_socket_info_request;
struct get_socket_info_reply;
struct enable_socket_event_request;
struct enable_socket_event_reply;
struct set_socket_deferred_request;
struct set_socket_deferred_reply;
struct alloc_console_request;
struct alloc_console_reply;
struct free_console_request;
struct free_console_reply;
struct console_renderer_event;
struct get_console_renderer_events_request;
struct get_console_renderer_events_reply;
struct open_console_request;
struct open_console_reply;
struct attach_console_request;
struct attach_console_reply;
struct get_console_wait_event_request;
struct get_console_wait_event_reply;
struct get_console_mode_request;
struct get_console_mode_reply;
struct set_console_mode_request;
struct set_console_mode_reply;
struct set_console_input_info_request;
struct set_console_input_info_reply;
struct get_console_input_info_request;
struct get_console_input_info_reply;
struct append_console_input_history_request;
struct append_console_input_history_reply;
struct get_console_input_history_request;
struct get_console_input_history_reply;
struct create_console_output_request;
struct create_console_output_reply;
struct set_console_output_info_request;
struct set_console_output_info_reply;
struct get_console_output_info_request;
struct get_console_output_info_reply;
struct write_console_input_request;
struct write_console_input_reply;
struct read_console_input_request;
struct read_console_input_reply;
struct write_console_output_request;
struct write_console_output_reply;
enum char_info_mode;
struct fill_console_output_request;
struct fill_console_output_reply;
struct read_console_output_request;
struct read_console_output_reply;
struct move_console_output_request;
struct move_console_output_reply;
struct send_console_signal_request;
struct send_console_signal_reply;
struct read_directory_changes_request;
struct read_directory_changes_reply;
struct read_change_request;
struct read_change_reply;
struct create_mapping_request;
struct create_mapping_reply;
struct open_mapping_request;
struct open_mapping_reply;
struct get_mapping_info_request;
struct get_mapping_info_reply;
struct map_view_request;
struct map_view_reply;
struct unmap_view_request;
struct unmap_view_reply;
struct get_mapping_committed_range_request;
struct get_mapping_committed_range_reply;
struct add_mapping_committed_range_request;
struct add_mapping_committed_range_reply;
struct is_same_mapping_request;
struct is_same_mapping_reply;
struct create_snapshot_request;
struct create_snapshot_reply;
struct next_process_request;
struct next_process_reply;
struct next_thread_request;
struct next_thread_reply;
struct wait_debug_event_request;
struct wait_debug_event_reply;
struct queue_exception_event_request;
struct queue_exception_event_reply;
struct get_exception_status_request;
struct get_exception_status_reply;
struct continue_debug_event_request;
struct continue_debug_event_reply;
struct debug_process_request;
struct debug_process_reply;
struct set_debugger_kill_on_exit_request;
struct set_debugger_kill_on_exit_reply;
struct read_process_memory_request;
struct read_process_memory_reply;
struct write_process_memory_request;
struct write_process_memory_reply;
struct create_key_request;
struct create_key_reply;
struct open_key_request;
struct open_key_reply;
struct delete_key_request;
struct delete_key_reply;
struct flush_key_request;
struct flush_key_reply;
struct enum_key_request;
struct enum_key_reply;
struct set_key_value_request;
struct set_key_value_reply;
struct get_key_value_request;
struct get_key_value_reply;
struct enum_key_value_request;
struct enum_key_value_reply;
struct delete_key_value_request;
struct delete_key_value_reply;
struct load_registry_request;
struct load_registry_reply;
struct unload_registry_request;
struct unload_registry_reply;
struct save_registry_request;
struct save_registry_reply;
struct set_registry_notification_request;
struct set_registry_notification_reply;
struct create_timer_request;
struct create_timer_reply;
struct open_timer_request;
struct open_timer_reply;
struct set_timer_request;
struct set_timer_reply;
struct cancel_timer_request;
struct cancel_timer_reply;
struct get_timer_info_request;
struct get_timer_info_reply;
struct get_thread_context_request;
struct get_thread_context_reply;
struct set_thread_context_request;
struct set_thread_context_reply;
struct get_selector_entry_request;
struct get_selector_entry_reply;
struct add_atom_request;
struct add_atom_reply;
struct delete_atom_request;
struct delete_atom_reply;
struct find_atom_request;
struct find_atom_reply;
struct get_atom_information_request;
struct get_atom_information_reply;
struct set_atom_information_request;
struct set_atom_information_reply;
struct empty_atom_table_request;
struct empty_atom_table_reply;
struct init_atom_table_request;
struct init_atom_table_reply;
struct get_msg_queue_request;
struct get_msg_queue_reply;
struct set_queue_fd_request;
struct set_queue_fd_reply;
struct set_queue_mask_request;
struct set_queue_mask_reply;
struct get_queue_status_request;
struct get_queue_status_reply;
struct get_process_idle_event_request;
struct get_process_idle_event_reply;
struct send_message_request;
struct send_message_reply;
struct post_quit_message_request;
struct post_quit_message_reply;
enum message_type;
struct send_hardware_message_request;
struct send_hardware_message_reply;
struct get_message_request;
struct get_message_reply;
struct reply_message_request;
struct reply_message_reply;
struct accept_hardware_message_request;
struct accept_hardware_message_reply;
struct get_message_reply_request;
struct get_message_reply_reply;
struct set_win_timer_request;
struct set_win_timer_reply;
struct kill_win_timer_request;
struct kill_win_timer_reply;
struct is_window_hung_request;
struct is_window_hung_reply;
struct get_serial_info_request;
struct get_serial_info_reply;
struct set_serial_info_request;
struct set_serial_info_reply;
struct register_async_request;
struct register_async_reply;
struct cancel_async_request;
struct cancel_async_reply;
struct get_async_result_request;
struct get_async_result_reply;
struct read_request;
struct read_reply;
struct write_request;
struct write_reply;
struct ioctl_request;
struct ioctl_reply;
struct set_irp_result_request;
struct set_irp_result_reply;
struct create_named_pipe_request;
struct create_named_pipe_reply;
struct set_named_pipe_info_request;
struct set_named_pipe_info_reply;
struct create_window_request;
struct create_window_reply;
struct destroy_window_request;
struct destroy_window_reply;
struct get_desktop_window_request;
struct get_desktop_window_reply;
struct set_window_owner_request;
struct set_window_owner_reply;
struct get_window_info_request;
struct get_window_info_reply;
struct set_window_info_request;
struct set_window_info_reply;
struct set_parent_request;
struct set_parent_reply;
struct get_window_parents_request;
struct get_window_parents_reply;
struct get_window_children_request;
struct get_window_children_reply;
struct get_window_children_from_point_request;
struct get_window_children_from_point_reply;
struct get_window_tree_request;
struct get_window_tree_reply;
struct set_window_pos_request;
struct set_window_pos_reply;
struct get_window_rectangles_request;
struct get_window_rectangles_reply;
enum coords_relative;
struct get_window_text_request;
struct get_window_text_reply;
struct set_window_text_request;
struct set_window_text_reply;
struct get_windows_offset_request;
struct get_windows_offset_reply;
struct get_visible_region_request;
struct get_visible_region_reply;
struct get_surface_region_request;
struct get_surface_region_reply;
struct get_window_region_request;
struct get_window_region_reply;
struct set_window_region_request;
struct set_window_region_reply;
struct get_update_region_request;
struct get_update_region_reply;
struct update_window_zorder_request;
struct update_window_zorder_reply;
struct redraw_window_request;
struct redraw_window_reply;
struct set_window_property_request;
struct set_window_property_reply;
struct remove_window_property_request;
struct remove_window_property_reply;
struct get_window_property_request;
struct get_window_property_reply;
struct get_window_properties_request;
struct get_window_properties_reply;
struct create_winstation_request;
struct create_winstation_reply;
struct open_winstation_request;
struct open_winstation_reply;
struct close_winstation_request;
struct close_winstation_reply;
struct get_process_winstation_request;
struct get_process_winstation_reply;
struct set_process_winstation_request;
struct set_process_winstation_reply;
struct enum_winstation_request;
struct enum_winstation_reply;
struct create_desktop_request;
struct create_desktop_reply;
struct open_desktop_request;
struct open_desktop_reply;
struct open_input_desktop_request;
struct open_input_desktop_reply;
struct close_desktop_request;
struct close_desktop_reply;
struct get_thread_desktop_request;
struct get_thread_desktop_reply;
struct set_thread_desktop_request;
struct set_thread_desktop_reply;
struct enum_desktop_request;
struct enum_desktop_reply;
struct set_user_object_info_request;
struct set_user_object_info_reply;
struct register_hotkey_request;
struct register_hotkey_reply;
struct unregister_hotkey_request;
struct unregister_hotkey_reply;
struct attach_thread_input_request;
struct attach_thread_input_reply;
struct get_thread_input_request;
struct get_thread_input_reply;
struct get_last_input_time_request;
struct get_last_input_time_reply;
struct get_key_state_request;
struct get_key_state_reply;
struct set_key_state_request;
struct set_key_state_reply;
struct set_foreground_window_request;
struct set_foreground_window_reply;
struct set_focus_window_request;
struct set_focus_window_reply;
struct set_active_window_request;
struct set_active_window_reply;
struct set_capture_window_request;
struct set_capture_window_reply;
struct set_caret_window_request;
struct set_caret_window_reply;
struct set_caret_info_request;
struct set_caret_info_reply;
enum caret_state;
struct set_hook_request;
struct set_hook_reply;
struct remove_hook_request;
struct remove_hook_reply;
struct start_hook_chain_request;
struct start_hook_chain_reply;
struct finish_hook_chain_request;
struct finish_hook_chain_reply;
struct get_hook_info_request;
struct get_hook_info_reply;
struct create_class_request;
struct create_class_reply;
struct destroy_class_request;
struct destroy_class_reply;
struct set_class_info_request;
struct set_class_info_reply;
struct open_clipboard_request;
struct open_clipboard_reply;
struct close_clipboard_request;
struct close_clipboard_reply;
struct empty_clipboard_request;
struct empty_clipboard_reply;
struct set_clipboard_data_request;
struct set_clipboard_data_reply;
struct get_clipboard_data_request;
struct get_clipboard_data_reply;
struct get_clipboard_formats_request;
struct get_clipboard_formats_reply;
struct enum_clipboard_formats_request;
struct enum_clipboard_formats_reply;
struct release_clipboard_request;
struct release_clipboard_reply;
struct get_clipboard_info_request;
struct get_clipboard_info_reply;
struct set_clipboard_viewer_request;
struct set_clipboard_viewer_reply;
struct add_clipboard_listener_request;
struct add_clipboard_listener_reply;
struct remove_clipboard_listener_request;
struct remove_clipboard_listener_reply;
struct open_token_request;
struct open_token_reply;
struct set_global_windows_request;
struct set_global_windows_reply;
struct adjust_token_privileges_request;
struct adjust_token_privileges_reply;
struct get_token_privileges_request;
struct get_token_privileges_reply;
struct check_token_privileges_request;
struct check_token_privileges_reply;
struct duplicate_token_request;
struct duplicate_token_reply;
struct access_check_request;
struct access_check_reply;
struct get_token_sid_request;
struct get_token_sid_reply;
struct get_token_groups_request;
struct get_token_groups_reply;
struct get_token_default_dacl_request;
struct get_token_default_dacl_reply;
struct set_token_default_dacl_request;
struct set_token_default_dacl_reply;
struct set_security_object_request;
struct set_security_object_reply;
struct get_security_object_request;
struct get_security_object_reply;
struct handle_info;
struct get_system_handles_request;
struct get_system_handles_reply;
struct create_mailslot_request;
struct create_mailslot_reply;
struct set_mailslot_info_request;
struct set_mailslot_info_reply;
struct create_directory_request;
struct create_directory_reply;
struct open_directory_request;
struct open_directory_reply;
struct get_directory_entry_request;
struct get_directory_entry_reply;
struct create_symlink_request;
struct create_symlink_reply;
struct open_symlink_request;
struct open_symlink_reply;
struct query_symlink_request;
struct query_symlink_reply;
struct get_object_info_request;
struct get_object_info_reply;
struct get_object_type_request;
struct get_object_type_reply;
struct unlink_object_request;
struct unlink_object_reply;
struct get_token_impersonation_level_request;
struct get_token_impersonation_level_reply;
struct allocate_locally_unique_id_request;
struct allocate_locally_unique_id_reply;
struct create_device_manager_request;
struct create_device_manager_reply;
struct create_device_request;
struct create_device_reply;
struct delete_device_request;
struct delete_device_reply;
struct get_next_device_request_request;
struct get_next_device_request_reply;
struct get_kernel_object_ptr_request;
struct get_kernel_object_ptr_reply;
struct set_kernel_object_ptr_request;
struct set_kernel_object_ptr_reply;
struct grab_kernel_object_request;
struct grab_kernel_object_reply;
struct release_kernel_object_request;
struct release_kernel_object_reply;
struct get_kernel_object_handle_request;
struct get_kernel_object_handle_reply;
struct make_process_system_request;
struct make_process_system_reply;
struct get_token_statistics_request;
struct get_token_statistics_reply;
struct create_completion_request;
struct create_completion_reply;
struct open_completion_request;
struct open_completion_reply;
struct add_completion_request;
struct add_completion_reply;
struct remove_completion_request;
struct remove_completion_reply;
struct query_completion_request;
struct query_completion_reply;
struct set_completion_info_request;
struct set_completion_info_reply;
struct add_fd_completion_request;
struct add_fd_completion_reply;
struct set_fd_completion_mode_request;
struct set_fd_completion_mode_reply;
struct set_fd_disp_info_request;
struct set_fd_disp_info_reply;
struct set_fd_name_info_request;
struct set_fd_name_info_reply;
struct get_window_layered_info_request;
struct get_window_layered_info_reply;
struct set_window_layered_info_request;
struct set_window_layered_info_reply;
struct alloc_user_handle_request;
struct alloc_user_handle_reply;
struct free_user_handle_request;
struct free_user_handle_reply;
struct set_cursor_request;
struct set_cursor_reply;
struct update_rawinput_devices_request;
struct update_rawinput_devices_reply;
struct get_suspend_context_request;
struct get_suspend_context_reply;
struct set_suspend_context_request;
struct set_suspend_context_reply;
struct create_job_request;
struct create_job_reply;
struct open_job_request;
struct open_job_reply;
struct assign_job_request;
struct assign_job_reply;
struct process_in_job_request;
struct process_in_job_reply;
struct set_job_limits_request;
struct set_job_limits_reply;
struct set_job_completion_port_request;
struct set_job_completion_port_reply;
struct terminate_job_request;
struct terminate_job_reply;
struct suspend_process_request;
struct suspend_process_reply;
struct resume_process_request;
struct resume_process_reply;
enum request;
union generic_request;
union generic_reply;
struct __server_iovec;
struct __server_request_info;
struct cp_info;
struct sbcs_table;
struct dbcs_table;
union cptable;
struct __wine_jmp_buf;
struct __tagWINE_FRAME;
enum wine_internal_message;
struct tagUSER_DRIVER;
enum user_obj_type;
struct user_object;
enum wm_char_mapping;
struct wm_char_mapping_data;
struct user_thread_info;
struct user_key_state_info;
struct hook_extra_info;
struct ICONRESDIR;
struct CURSORDIR;
struct CURSORICONDIRENTRY;
struct CURSORICONDIR;
struct CURSORICONFILEDIRENTRY;
struct CURSORICONFILEDIR;
struct tagWND;
enum builtin_winprocs;
struct builtin_class_descr;
struct wow_handlers16;
struct wow_handlers32;
struct HEADCOMBO;
struct tagDIALOGINFO;
struct MENUITEM;
struct POPUPMENU;
struct MTRACKER;
enum hittest;
enum tag_SCRIPT_JUSTIFY;
struct tag_SCRIPT_CONTROL;
struct SCRIPT_PROPERTIES;
struct tag_SCRIPT_STATE;
struct tag_SCRIPT_ANALYSIS;
struct tag_SCRIPT_ITEM;
struct tag_SCRIPT_DIGITSUBSTITUTE;
struct tag_SCRIPT_FONTPROPERTIES;
struct tag_SCRIPT_TABDEF;
struct tag_SCRIPT_VISATTR;
struct tag_SCRIPT_LOGATTR;
struct tagGOFFSET;
struct tagOPENTYPE_FEATURE_RECORD;
struct tagSCRIPT_GLYPHPROP;
struct tagSCRIPT_CHARPROP;
struct tagTEXTRANGE_PROPERTIES;
struct tag_ellipsis_data;

typedef signed char INT8;

typedef signed char* PINT8;

typedef short INT16;

typedef short* PINT16;

typedef int INT32;

typedef int* PINT32;

typedef unsigned char UINT8;

typedef unsigned char* PUINT8;

typedef unsigned short UINT16;

typedef unsigned short* PUINT16;

typedef unsigned int UINT32;

typedef unsigned int* PUINT32;

typedef int LONG32;

typedef int* PLONG32;

typedef unsigned int ULONG32;

typedef unsigned int* PULONG32;

typedef unsigned int DWORD32;

typedef unsigned int* PDWORD32;

typedef long INT64;

typedef long* PINT64;

typedef unsigned long UINT64;

typedef unsigned long* PUINT64;

typedef long LONG64;

typedef long* PLONG64;

typedef unsigned long ULONG64;

typedef unsigned long* PULONG64;

typedef unsigned long DWORD64;

typedef unsigned long* PDWORD64;

typedef long INT_PTR;

typedef long* PINT_PTR;

typedef long LONG_PTR;

typedef long* PLONG_PTR;

typedef unsigned long UINT_PTR;

typedef unsigned long* PUINT_PTR;

typedef unsigned long ULONG_PTR;

typedef unsigned long* PULONG_PTR;

typedef ULONG_PTR DWORD_PTR;

typedef ULONG_PTR* PDWORD_PTR;

typedef long SHANDLE_PTR;

typedef unsigned long HANDLE_PTR;

typedef int HALF_PTR;

typedef int* PHALF_PTR;

typedef unsigned int UHALF_PTR;

typedef unsigned int* PUHALF_PTR;

typedef LONG_PTR SSIZE_T;

typedef LONG_PTR* PSSIZE_T;

typedef ULONG_PTR SIZE_T;

typedef ULONG_PTR* PSIZE_T;

typedef ULONG_PTR KAFFINITY;

typedef ULONG_PTR* PKAFFINITY;

typedef void* DLL_DIRECTORY_COOKIE;

typedef void** PDLL_DIRECTORY_COOKIE;

enum _EVENT_TYPE
{
    _EVENT_TYPE_DUMMY = 0
};


typedef enum _EVENT_TYPE EVENT_TYPE;

enum _TIMER_TYPE
{
    _TIMER_TYPE_DUMMY = 0
};


typedef enum _TIMER_TYPE TIMER_TYPE;

enum _WAIT_TYPE
{
    _WAIT_TYPE_DUMMY = 0
};


typedef enum _WAIT_TYPE WAIT_TYPE;

typedef LONG NTSTATUS;

typedef const char* PCSZ;

typedef short CSHORT;

typedef CSHORT* PCSHORT;

struct _STRING
{
    USHORT Length;
    USHORT MaximumLength;
    PCHAR Buffer;
};


typedef struct _STRING STRING;

typedef struct _STRING* PSTRING;

typedef STRING ANSI_STRING;

typedef PSTRING PANSI_STRING;

typedef const STRING* PCANSI_STRING;

typedef STRING OEM_STRING;

typedef PSTRING POEM_STRING;

typedef const STRING* PCOEM_STRING;

struct _UNICODE_STRING
{
    USHORT Length;
    USHORT MaximumLength;
    PWSTR Buffer;
};


typedef struct _UNICODE_STRING UNICODE_STRING;

typedef struct _UNICODE_STRING* PUNICODE_STRING;

typedef const UNICODE_STRING* PCUNICODE_STRING;

struct _RTL_SYSTEM_TIME
{
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliseconds;
};


typedef struct _RTL_SYSTEM_TIME RTL_SYSTEM_TIME;

typedef struct _RTL_SYSTEM_TIME* PRTL_SYSTEM_TIME;

struct _RTL_TIME_ZONE_INFORMATION
{
    LONG Bias;
    WCHAR StandardName[32];
    RTL_SYSTEM_TIME StandardDate;
    LONG StandardBias;
    WCHAR DaylightName[32];
    RTL_SYSTEM_TIME DaylightDate;
    LONG DaylightBias;
};


typedef struct _RTL_TIME_ZONE_INFORMATION RTL_TIME_ZONE_INFORMATION;

typedef struct _RTL_TIME_ZONE_INFORMATION* PRTL_TIME_ZONE_INFORMATION;

struct _RTL_TIME_DYNAMIC_ZONE_INFORMATION
{
    LONG Bias;
    WCHAR StandardName[32];
    RTL_SYSTEM_TIME StandardDate;
    LONG StandardBias;
    WCHAR DaylightName[32];
    RTL_SYSTEM_TIME DaylightDate;
    LONG DaylightBias;
    WCHAR TimeZoneKeyName[128];
    BOOLEAN DynamicDaylightTimeDisabled;
};


typedef struct _RTL_TIME_DYNAMIC_ZONE_INFORMATION RTL_DYNAMIC_TIME_ZONE_INFORMATION;

typedef struct _RTL_TIME_DYNAMIC_ZONE_INFORMATION* PRTL_DYNAMIC_TIME_ZONE_INFORMATION;

struct _CLIENT_ID
{
    HANDLE UniqueProcess;
    HANDLE UniqueThread;
};


typedef struct _CLIENT_ID CLIENT_ID;

typedef struct _CLIENT_ID* PCLIENT_ID;

struct _CURDIR
{
    UNICODE_STRING DosPath;
    PVOID Handle;
};


typedef struct _CURDIR CURDIR;

typedef struct _CURDIR* PCURDIR;

struct RTL_DRIVE_LETTER_CURDIR
{
    USHORT Flags;
    USHORT Length;
    ULONG TimeStamp;
    UNICODE_STRING DosPath;
};


typedef struct RTL_DRIVE_LETTER_CURDIR RTL_DRIVE_LETTER_CURDIR;

typedef struct RTL_DRIVE_LETTER_CURDIR* PRTL_DRIVE_LETTER_CURDIR;

struct _RTL_RELATIVE_NAME
{
    UNICODE_STRING RelativeName;
    HANDLE ContainerDirectory;
    void* CurDirRef;
};


typedef struct _RTL_RELATIVE_NAME RTL_RELATIVE_NAME;

typedef struct _RTL_RELATIVE_NAME* PRTL_RELATIVE_NAME;

struct tagRTL_BITMAP
{
    ULONG SizeOfBitMap;
    PULONG Buffer;
};


typedef struct tagRTL_BITMAP RTL_BITMAP;

typedef struct tagRTL_BITMAP* PRTL_BITMAP;

typedef const RTL_BITMAP* PCRTL_BITMAP;

struct tagRTL_BITMAP_RUN
{
    ULONG StartingIndex;
    ULONG NumberOfBits;
};


typedef struct tagRTL_BITMAP_RUN RTL_BITMAP_RUN;

typedef struct tagRTL_BITMAP_RUN* PRTL_BITMAP_RUN;

typedef const RTL_BITMAP_RUN* PCRTL_BITMAP_RUN;

struct _RTL_USER_PROCESS_PARAMETERS
{
    ULONG AllocationSize;
    ULONG Size;
    ULONG Flags;
    ULONG DebugFlags;
    HANDLE ConsoleHandle;
    ULONG ConsoleFlags;
    HANDLE hStdInput;
    HANDLE hStdOutput;
    HANDLE hStdError;
    CURDIR CurrentDirectory;
    UNICODE_STRING DllPath;
    UNICODE_STRING ImagePathName;
    UNICODE_STRING CommandLine;
    PWSTR Environment;
    ULONG dwX;
    ULONG dwY;
    ULONG dwXSize;
    ULONG dwYSize;
    ULONG dwXCountChars;
    ULONG dwYCountChars;
    ULONG dwFillAttribute;
    ULONG dwFlags;
    ULONG wShowWindow;
    UNICODE_STRING WindowTitle;
    UNICODE_STRING Desktop;
    UNICODE_STRING ShellInfo;
    UNICODE_STRING RuntimeInfo;
    RTL_DRIVE_LETTER_CURDIR DLCurrentDirectory[32];
};


typedef struct _RTL_USER_PROCESS_PARAMETERS RTL_USER_PROCESS_PARAMETERS;

typedef struct _RTL_USER_PROCESS_PARAMETERS* PRTL_USER_PROCESS_PARAMETERS;

struct _PEB_LDR_DATA
{
    ULONG Length;
    BOOLEAN Initialized;
    PVOID SsHandle;
    LIST_ENTRY InLoadOrderModuleList;
    LIST_ENTRY InMemoryOrderModuleList;
    LIST_ENTRY InInitializationOrderModuleList;
    PVOID EntryInProgress;
};


typedef struct _PEB_LDR_DATA PEB_LDR_DATA;

typedef struct _PEB_LDR_DATA* PPEB_LDR_DATA;

struct _GDI_TEB_BATCH
{
    ULONG Offset;
    HANDLE HDC;
    ULONG Buffer[310];
};


typedef struct _GDI_TEB_BATCH GDI_TEB_BATCH;

struct _RTL_ACTIVATION_CONTEXT_STACK_FRAME
{
    struct _RTL_ACTIVATION_CONTEXT_STACK_FRAME* Previous;
    struct _ACTIVATION_CONTEXT* ActivationContext;
    ULONG Flags;
};


typedef struct _RTL_ACTIVATION_CONTEXT_STACK_FRAME RTL_ACTIVATION_CONTEXT_STACK_FRAME;

typedef struct _RTL_ACTIVATION_CONTEXT_STACK_FRAME* PRTL_ACTIVATION_CONTEXT_STACK_FRAME;

struct _ACTIVATION_CONTEXT_STACK
{
    ULONG Flags;
    ULONG NextCookieSequenceNumber;
    RTL_ACTIVATION_CONTEXT_STACK_FRAME* ActiveFrame;
    LIST_ENTRY FrameListCache;
};


typedef struct _ACTIVATION_CONTEXT_STACK ACTIVATION_CONTEXT_STACK;

typedef struct _ACTIVATION_CONTEXT_STACK* PACTIVATION_CONTEXT_STACK;

struct _TEB_ACTIVE_FRAME_CONTEXT
{
    ULONG Flags;
    const char* FrameName;
};


typedef struct _TEB_ACTIVE_FRAME_CONTEXT TEB_ACTIVE_FRAME_CONTEXT;

typedef struct _TEB_ACTIVE_FRAME_CONTEXT* PTEB_ACTIVE_FRAME_CONTEXT;

struct _TEB_ACTIVE_FRAME_CONTEXT_EX
{
    TEB_ACTIVE_FRAME_CONTEXT BasicContext;
    const char* SourceLocation;
};


typedef struct _TEB_ACTIVE_FRAME_CONTEXT_EX TEB_ACTIVE_FRAME_CONTEXT_EX;

typedef struct _TEB_ACTIVE_FRAME_CONTEXT_EX* PTEB_ACTIVE_FRAME_CONTEXT_EX;

struct _TEB_ACTIVE_FRAME
{
    ULONG Flags;
    struct _TEB_ACTIVE_FRAME* Previous;
    TEB_ACTIVE_FRAME_CONTEXT* Context;
};


typedef struct _TEB_ACTIVE_FRAME TEB_ACTIVE_FRAME;

typedef struct _TEB_ACTIVE_FRAME* PTEB_ACTIVE_FRAME;

struct _TEB_ACTIVE_FRAME_EX
{
    TEB_ACTIVE_FRAME BasicFrame;
    void* ExtensionIdentifier;
};


typedef struct _TEB_ACTIVE_FRAME_EX TEB_ACTIVE_FRAME_EX;

typedef struct _TEB_ACTIVE_FRAME_EX* PTEB_ACTIVE_FRAME_EX;

struct _PEB
{
    BOOLEAN InheritedAddressSpace;
    BOOLEAN ReadImageFileExecOptions;
    BOOLEAN BeingDebugged;
    BOOLEAN SpareBool;
    HANDLE Mutant;
    HMODULE ImageBaseAddress;
    PPEB_LDR_DATA LdrData;
    RTL_USER_PROCESS_PARAMETERS* ProcessParameters;
    PVOID SubSystemData;
    HANDLE ProcessHeap;
    PRTL_CRITICAL_SECTION FastPebLock;
    PVOID FastPebLockRoutine;
    PVOID FastPebUnlockRoutine;
    ULONG EnvironmentUpdateCount;
    PVOID KernelCallbackTable;
    ULONG Reserved[2];
    PVOID FreeList;
    ULONG TlsExpansionCounter;
    PRTL_BITMAP TlsBitmap;
    ULONG TlsBitmapBits[2];
    PVOID ReadOnlySharedMemoryBase;
    PVOID ReadOnlySharedMemoryHeap;
    PVOID* ReadOnlyStaticServerData;
    PVOID AnsiCodePageData;
    PVOID OemCodePageData;
    PVOID UnicodeCaseTableData;
    ULONG NumberOfProcessors;
    ULONG NtGlobalFlag;
    LARGE_INTEGER CriticalSectionTimeout;
    SIZE_T HeapSegmentReserve;
    SIZE_T HeapSegmentCommit;
    SIZE_T HeapDeCommitTotalFreeThreshold;
    SIZE_T HeapDeCommitFreeBlockThreshold;
    ULONG NumberOfHeaps;
    ULONG MaximumNumberOfHeaps;
    PVOID* ProcessHeaps;
    PVOID GdiSharedHandleTable;
    PVOID ProcessStarterHelper;
    PVOID GdiDCAttributeList;
    PVOID LoaderLock;
    ULONG OSMajorVersion;
    ULONG OSMinorVersion;
    ULONG OSBuildNumber;
    ULONG OSPlatformId;
    ULONG ImageSubSystem;
    ULONG ImageSubSystemMajorVersion;
    ULONG ImageSubSystemMinorVersion;
    ULONG ImageProcessAffinityMask;
    HANDLE GdiHandleBuffer[28];
    ULONG unknown[6];
    PVOID PostProcessInitRoutine;
    PRTL_BITMAP TlsExpansionBitmap;
    ULONG TlsExpansionBitmapBits[32];
    ULONG SessionId;
    ULARGE_INTEGER AppCompatFlags;
    ULARGE_INTEGER AppCompatFlagsUser;
    PVOID ShimData;
    PVOID AppCompatInfo;
    UNICODE_STRING CSDVersion;
    PVOID ActivationContextData;
    PVOID ProcessAssemblyStorageMap;
    PVOID SystemDefaultActivationData;
    PVOID SystemAssemblyStorageMap;
    SIZE_T MinimumStackCommit;
    PVOID* FlsCallback;
    LIST_ENTRY FlsListHead;
    PRTL_BITMAP FlsBitmap;
    ULONG FlsBitmapBits[4];
};


typedef struct _PEB PEB;

typedef struct _PEB* PPEB;

struct _TEB
{
    NT_TIB Tib;
    PVOID EnvironmentPointer;
    CLIENT_ID ClientId;
    PVOID ActiveRpcHandle;
    PVOID ThreadLocalStoragePointer;
    PPEB Peb;
    ULONG LastErrorValue;
    ULONG CountOfOwnedCriticalSections;
    PVOID CsrClientThread;
    PVOID Win32ThreadInfo;
    ULONG Win32ClientInfo[31];
    PVOID WOW32Reserved;
    ULONG CurrentLocale;
    ULONG FpSoftwareStatusRegister;
    PVOID SystemReserved1[54];
    LONG ExceptionCode;
    ACTIVATION_CONTEXT_STACK ActivationContextStack;
    BYTE SpareBytes1[24];
    PVOID SystemReserved2[10];
    GDI_TEB_BATCH GdiTebBatch;
    HANDLE gdiRgn;
    HANDLE gdiPen;
    HANDLE gdiBrush;
    CLIENT_ID RealClientId;
    HANDLE GdiCachedProcessHandle;
    ULONG GdiClientPID;
    ULONG GdiClientTID;
    PVOID GdiThreadLocaleInfo;
    ULONG UserReserved[5];
    PVOID glDispatchTable[280];
    PVOID glReserved1[26];
    PVOID glReserved2;
    PVOID glSectionInfo;
    PVOID glSection;
    PVOID glTable;
    PVOID glCurrentRC;
    PVOID glContext;
    ULONG LastStatusValue;
    UNICODE_STRING StaticUnicodeString;
    WCHAR StaticUnicodeBuffer[261];
    PVOID DeallocationStack;
    PVOID TlsSlots[64];
    LIST_ENTRY TlsLinks;
    PVOID Vdm;
    PVOID ReservedForNtRpc;
    PVOID DbgSsReserved[2];
    ULONG HardErrorDisabled;
    PVOID Instrumentation[16];
    PVOID WinSockData;
    ULONG GdiBatchCount;
    ULONG Spare2;
    ULONG GuaranteedStackBytes;
    PVOID ReservedForPerf;
    PVOID ReservedForOle;
    ULONG WaitingOnLoaderLock;
    PVOID Reserved5[3];
    PVOID* TlsExpansionSlots;
    PVOID DeallocationBStore;
    PVOID BStoreLimit;
    ULONG ImpersonationLocale;
    ULONG IsImpersonating;
    PVOID NlsCache;
    PVOID ShimData;
    ULONG HeapVirtualAffinity;
    PVOID CurrentTransactionHandle;
    TEB_ACTIVE_FRAME* ActiveFrame;
    PVOID* FlsSlots;
};


typedef struct _TEB TEB;

typedef struct _TEB* PTEB;

enum _FILE_INFORMATION_CLASS
{
    _FILE_INFORMATION_CLASS_DUMMY = 0
};


typedef enum _FILE_INFORMATION_CLASS FILE_INFORMATION_CLASS;

typedef enum _FILE_INFORMATION_CLASS* PFILE_INFORMATION_CLASS;

struct _FILE_DIRECTORY_INFORMATION
{
    ULONG NextEntryOffset;
    ULONG FileIndex;
    LARGE_INTEGER CreationTime;
    LARGE_INTEGER LastAccessTime;
    LARGE_INTEGER LastWriteTime;
    LARGE_INTEGER ChangeTime;
    LARGE_INTEGER EndOfFile;
    LARGE_INTEGER AllocationSize;
    ULONG FileAttributes;
    ULONG FileNameLength;
    WCHAR FileName[1];
};


typedef struct _FILE_DIRECTORY_INFORMATION FILE_DIRECTORY_INFORMATION;

typedef struct _FILE_DIRECTORY_INFORMATION* PFILE_DIRECTORY_INFORMATION;

struct _FILE_FULL_DIRECTORY_INFORMATION
{
    ULONG NextEntryOffset;
    ULONG FileIndex;
    LARGE_INTEGER CreationTime;
    LARGE_INTEGER LastAccessTime;
    LARGE_INTEGER LastWriteTime;
    LARGE_INTEGER ChangeTime;
    LARGE_INTEGER EndOfFile;
    LARGE_INTEGER AllocationSize;
    ULONG FileAttributes;
    ULONG FileNameLength;
    ULONG EaSize;
    WCHAR FileName[1];
};


typedef struct _FILE_FULL_DIRECTORY_INFORMATION FILE_FULL_DIRECTORY_INFORMATION;

typedef struct _FILE_FULL_DIRECTORY_INFORMATION* PFILE_FULL_DIRECTORY_INFORMATION;

typedef struct _FILE_FULL_DIRECTORY_INFORMATION FILE_FULL_DIR_INFORMATION;

typedef struct _FILE_FULL_DIRECTORY_INFORMATION* PFILE_FULL_DIR_INFORMATION;

struct _FILE_ID_FULL_DIRECTORY_INFORMATION
{
    ULONG NextEntryOffset;
    ULONG FileIndex;
    LARGE_INTEGER CreationTime;
    LARGE_INTEGER LastAccessTime;
    LARGE_INTEGER LastWriteTime;
    LARGE_INTEGER ChangeTime;
    LARGE_INTEGER EndOfFile;
    LARGE_INTEGER AllocationSize;
    ULONG FileAttributes;
    ULONG FileNameLength;
    ULONG EaSize;
    LARGE_INTEGER FileId;
    WCHAR FileName[1];
};


typedef struct _FILE_ID_FULL_DIRECTORY_INFORMATION FILE_ID_FULL_DIRECTORY_INFORMATION;

typedef struct _FILE_ID_FULL_DIRECTORY_INFORMATION* PFILE_ID_FULL_DIRECTORY_INFORMATION;

struct _FILE_BOTH_DIRECTORY_INFORMATION
{
    ULONG NextEntryOffset;
    ULONG FileIndex;
    LARGE_INTEGER CreationTime;
    LARGE_INTEGER LastAccessTime;
    LARGE_INTEGER LastWriteTime;
    LARGE_INTEGER ChangeTime;
    LARGE_INTEGER EndOfFile;
    LARGE_INTEGER AllocationSize;
    ULONG FileAttributes;
    ULONG FileNameLength;
    ULONG EaSize;
    CHAR ShortNameLength;
    WCHAR ShortName[12];
    WCHAR FileName[1];
};


typedef struct _FILE_BOTH_DIRECTORY_INFORMATION FILE_BOTH_DIRECTORY_INFORMATION;

typedef struct _FILE_BOTH_DIRECTORY_INFORMATION* PFILE_BOTH_DIRECTORY_INFORMATION;

typedef struct _FILE_BOTH_DIRECTORY_INFORMATION FILE_BOTH_DIR_INFORMATION;

typedef struct _FILE_BOTH_DIRECTORY_INFORMATION* PFILE_BOTH_DIR_INFORMATION;

struct _FILE_ID_BOTH_DIRECTORY_INFORMATION
{
    ULONG NextEntryOffset;
    ULONG FileIndex;
    LARGE_INTEGER CreationTime;
    LARGE_INTEGER LastAccessTime;
    LARGE_INTEGER LastWriteTime;
    LARGE_INTEGER ChangeTime;
    LARGE_INTEGER EndOfFile;
    LARGE_INTEGER AllocationSize;
    ULONG FileAttributes;
    ULONG FileNameLength;
    ULONG EaSize;
    CHAR ShortNameLength;
    WCHAR ShortName[12];
    LARGE_INTEGER FileId;
    WCHAR FileName[1];
};


typedef struct _FILE_ID_BOTH_DIRECTORY_INFORMATION FILE_ID_BOTH_DIRECTORY_INFORMATION;

typedef struct _FILE_ID_BOTH_DIRECTORY_INFORMATION* PFILE_ID_BOTH_DIRECTORY_INFORMATION;

struct _FILE_ID_GLOBAL_TX_DIR_INFORMATION
{
    ULONG NextEntryOffset;
    ULONG FileIndex;
    LARGE_INTEGER CreationTime;
    LARGE_INTEGER LastAccessTime;
    LARGE_INTEGER LastWriteTime;
    LARGE_INTEGER ChangeTime;
    LARGE_INTEGER EndOfFile;
    LARGE_INTEGER AllocationSize;
    ULONG FileAttributes;
    ULONG FileNameLength;
    LARGE_INTEGER FileId;
    GUID LockingTransactionId;
    ULONG TxInfoFlags;
    WCHAR FileName[1];
};


typedef struct _FILE_ID_GLOBAL_TX_DIR_INFORMATION FILE_ID_GLOBAL_TX_DIR_INFORMATION;

typedef struct _FILE_ID_GLOBAL_TX_DIR_INFORMATION* PFILE_ID_GLOBAL_TX_DIR_INFORMATION;

struct _FILE_BASIC_INFORMATION
{
    LARGE_INTEGER CreationTime;
    LARGE_INTEGER LastAccessTime;
    LARGE_INTEGER LastWriteTime;
    LARGE_INTEGER ChangeTime;
    ULONG FileAttributes;
};


typedef struct _FILE_BASIC_INFORMATION FILE_BASIC_INFORMATION;

typedef struct _FILE_BASIC_INFORMATION* PFILE_BASIC_INFORMATION;

struct _FILE_STANDARD_INFORMATION
{
    LARGE_INTEGER AllocationSize;
    LARGE_INTEGER EndOfFile;
    ULONG NumberOfLinks;
    BOOLEAN DeletePending;
    BOOLEAN Directory;
};


typedef struct _FILE_STANDARD_INFORMATION FILE_STANDARD_INFORMATION;

typedef struct _FILE_STANDARD_INFORMATION* PFILE_STANDARD_INFORMATION;

struct _FILE_INTERNAL_INFORMATION
{
    LARGE_INTEGER IndexNumber;
};


typedef struct _FILE_INTERNAL_INFORMATION FILE_INTERNAL_INFORMATION;

typedef struct _FILE_INTERNAL_INFORMATION* PFILE_INTERNAL_INFORMATION;

struct _FILE_ID_128
{
    UCHAR Identifier[16];
};


typedef struct _FILE_ID_128 FILE_ID_128;

typedef struct _FILE_ID_128* PFILE_ID_128;

struct _FILE_ID_INFORMATION
{
    ULONGLONG VolumeSerialNumber;
    FILE_ID_128 FileId;
};


typedef struct _FILE_ID_INFORMATION FILE_ID_INFORMATION;

typedef struct _FILE_ID_INFORMATION* PFILE_ID_INFORMATION;

struct _FILE_EA_INFORMATION
{
    ULONG EaSize;
};


typedef struct _FILE_EA_INFORMATION FILE_EA_INFORMATION;

typedef struct _FILE_EA_INFORMATION* PFILE_EA_INFORMATION;

struct _FILE_ACCESS_INFORMATION
{
    ACCESS_MASK AccessFlags;
};


typedef struct _FILE_ACCESS_INFORMATION FILE_ACCESS_INFORMATION;

typedef struct _FILE_ACCESS_INFORMATION* PFILE_ACCESS_INFORMATION;

struct _FILE_NAME_INFORMATION
{
    ULONG FileNameLength;
    WCHAR FileName[1];
};


typedef struct _FILE_NAME_INFORMATION FILE_NAME_INFORMATION;

typedef struct _FILE_NAME_INFORMATION* PFILE_NAME_INFORMATION;

struct _FILE_RENAME_INFORMATION
{
    BOOLEAN Replace;
    HANDLE RootDir;
    ULONG FileNameLength;
    WCHAR FileName[1];
};


typedef struct _FILE_RENAME_INFORMATION FILE_RENAME_INFORMATION;

typedef struct _FILE_RENAME_INFORMATION* PFILE_RENAME_INFORMATION;

struct _FILE_LINK_INFORMATION
{
    BOOLEAN ReplaceIfExists;
    HANDLE RootDirectory;
    ULONG FileNameLength;
    WCHAR FileName[1];
};


typedef struct _FILE_LINK_INFORMATION FILE_LINK_INFORMATION;

typedef struct _FILE_LINK_INFORMATION* PFILE_LINK_INFORMATION;

struct _FILE_NAMES_INFORMATION
{
    ULONG NextEntryOffset;
    ULONG FileIndex;
    ULONG FileNameLength;
    WCHAR FileName[1];
};


typedef struct _FILE_NAMES_INFORMATION FILE_NAMES_INFORMATION;

typedef struct _FILE_NAMES_INFORMATION* PFILE_NAMES_INFORMATION;

struct _FILE_DISPOSITION_INFORMATION
{
    BOOLEAN DoDeleteFile;
};


typedef struct _FILE_DISPOSITION_INFORMATION FILE_DISPOSITION_INFORMATION;

typedef struct _FILE_DISPOSITION_INFORMATION* PFILE_DISPOSITION_INFORMATION;

struct _FILE_POSITION_INFORMATION
{
    LARGE_INTEGER CurrentByteOffset;
};


typedef struct _FILE_POSITION_INFORMATION FILE_POSITION_INFORMATION;

typedef struct _FILE_POSITION_INFORMATION* PFILE_POSITION_INFORMATION;

struct _FILE_ALIGNMENT_INFORMATION
{
    ULONG AlignmentRequirement;
};


typedef struct _FILE_ALIGNMENT_INFORMATION FILE_ALIGNMENT_INFORMATION;

typedef struct _FILE_ALIGNMENT_INFORMATION* PFILE_ALIGNMENT_INFORMATION;

struct _FILE_ALLOCATION_INFORMATION
{
    LARGE_INTEGER AllocationSize;
};


typedef struct _FILE_ALLOCATION_INFORMATION FILE_ALLOCATION_INFORMATION;

typedef struct _FILE_ALLOCATION_INFORMATION* PFILE_ALLOCATION_INFORMATION;

struct _FILE_END_OF_FILE_INFORMATION
{
    LARGE_INTEGER EndOfFile;
};


typedef struct _FILE_END_OF_FILE_INFORMATION FILE_END_OF_FILE_INFORMATION;

typedef struct _FILE_END_OF_FILE_INFORMATION* PFILE_END_OF_FILE_INFORMATION;

struct _FILE_NETWORK_OPEN_INFORMATION
{
    LARGE_INTEGER CreationTime;
    LARGE_INTEGER LastAccessTime;
    LARGE_INTEGER LastWriteTime;
    LARGE_INTEGER ChangeTime;
    LARGE_INTEGER AllocationSize;
    LARGE_INTEGER EndOfFile;
    ULONG FileAttributes;
};


typedef struct _FILE_NETWORK_OPEN_INFORMATION FILE_NETWORK_OPEN_INFORMATION;

typedef struct _FILE_NETWORK_OPEN_INFORMATION* PFILE_NETWORK_OPEN_INFORMATION;

struct _FILE_FULL_EA_INFORMATION
{
    ULONG NextEntryOffset;
    UCHAR Flags;
    UCHAR EaNameLength;
    USHORT EaValueLength;
    CHAR EaName[1];
};


typedef struct _FILE_FULL_EA_INFORMATION FILE_FULL_EA_INFORMATION;

typedef struct _FILE_FULL_EA_INFORMATION* PFILE_FULL_EA_INFORMATION;

struct _FILE_MODE_INFORMATION
{
    ULONG Mode;
};


typedef struct _FILE_MODE_INFORMATION FILE_MODE_INFORMATION;

typedef struct _FILE_MODE_INFORMATION* PFILE_MODE_INFORMATION;

struct _FILE_STREAM_INFORMATION
{
    ULONG NextEntryOffset;
    ULONG StreamNameLength;
    LARGE_INTEGER StreamSize;
    LARGE_INTEGER StreamAllocationSize;
    WCHAR StreamName[1];
};


typedef struct _FILE_STREAM_INFORMATION FILE_STREAM_INFORMATION;

typedef struct _FILE_STREAM_INFORMATION* PFILE_STREAM_INFORMATION;

struct _FILE_ATTRIBUTE_TAG_INFORMATION
{
    ULONG FileAttributes;
    ULONG ReparseTag;
};


typedef struct _FILE_ATTRIBUTE_TAG_INFORMATION FILE_ATTRIBUTE_TAG_INFORMATION;

typedef struct _FILE_ATTRIBUTE_TAG_INFORMATION* PFILE_ATTRIBUTE_TAG_INFORMATION;

struct _FILE_MAILSLOT_QUERY_INFORMATION
{
    ULONG MaximumMessageSize;
    ULONG MailslotQuota;
    ULONG NextMessageSize;
    ULONG MessagesAvailable;
    LARGE_INTEGER ReadTimeout;
};


typedef struct _FILE_MAILSLOT_QUERY_INFORMATION FILE_MAILSLOT_QUERY_INFORMATION;

typedef struct _FILE_MAILSLOT_QUERY_INFORMATION* PFILE_MAILSLOT_QUERY_INFORMATION;

struct _FILE_MAILSLOT_SET_INFORMATION
{
    LARGE_INTEGER ReadTimeout;
};


typedef struct _FILE_MAILSLOT_SET_INFORMATION FILE_MAILSLOT_SET_INFORMATION;

typedef struct _FILE_MAILSLOT_SET_INFORMATION* PFILE_MAILSLOT_SET_INFORMATION;

struct _FILE_PIPE_INFORMATION
{
    ULONG ReadMode;
    ULONG CompletionMode;
};


typedef struct _FILE_PIPE_INFORMATION FILE_PIPE_INFORMATION;

typedef struct _FILE_PIPE_INFORMATION* PFILE_PIPE_INFORMATION;

struct _FILE_PIPE_LOCAL_INFORMATION
{
    ULONG NamedPipeType;
    ULONG NamedPipeConfiguration;
    ULONG MaximumInstances;
    ULONG CurrentInstances;
    ULONG InboundQuota;
    ULONG ReadDataAvailable;
    ULONG OutboundQuota;
    ULONG WriteQuotaAvailable;
    ULONG NamedPipeState;
    ULONG NamedPipeEnd;
};


typedef struct _FILE_PIPE_LOCAL_INFORMATION FILE_PIPE_LOCAL_INFORMATION;

typedef struct _FILE_PIPE_LOCAL_INFORMATION* PFILE_PIPE_LOCAL_INFORMATION;

struct _FILE_OBJECTID_INFORMATION
{
    LONGLONG FileReference;
    UCHAR ObjectId[16];
};


typedef struct _FILE_OBJECTID_INFORMATION FILE_OBJECTID_INFORMATION;

typedef struct _FILE_OBJECTID_INFORMATION* PFILE_OBJECTID_INFORMATION;

struct _FILE_QUOTA_INFORMATION
{
    ULONG NextEntryOffset;
    ULONG SidLength;
    LARGE_INTEGER ChangeTime;
    LARGE_INTEGER QuotaUsed;
    LARGE_INTEGER QuotaThreshold;
    LARGE_INTEGER QuotaLimit;
    SID Sid;
};


typedef struct _FILE_QUOTA_INFORMATION FILE_QUOTA_INFORMATION;

typedef struct _FILE_QUOTA_INFORMATION* PFILE_QUOTA_INFORMATION;

struct _FILE_REPARSE_POINT_INFORMATION
{
    LONGLONG FileReference;
    ULONG Tag;
};


typedef struct _FILE_REPARSE_POINT_INFORMATION FILE_REPARSE_POINT_INFORMATION;

typedef struct _FILE_REPARSE_POINT_INFORMATION* PFILE_REPARSE_POINT_INFORMATION;

struct _FILE_ALL_INFORMATION
{
    FILE_BASIC_INFORMATION BasicInformation;
    FILE_STANDARD_INFORMATION StandardInformation;
    FILE_INTERNAL_INFORMATION InternalInformation;
    FILE_EA_INFORMATION EaInformation;
    FILE_ACCESS_INFORMATION AccessInformation;
    FILE_POSITION_INFORMATION PositionInformation;
    FILE_MODE_INFORMATION ModeInformation;
    FILE_ALIGNMENT_INFORMATION AlignmentInformation;
    FILE_NAME_INFORMATION NameInformation;
};


typedef struct _FILE_ALL_INFORMATION FILE_ALL_INFORMATION;

typedef struct _FILE_ALL_INFORMATION* PFILE_ALL_INFORMATION;

struct _FILE_IO_COMPLETION_NOTIFICATION_INFORMATION
{
    ULONG Flags;
};


typedef struct _FILE_IO_COMPLETION_NOTIFICATION_INFORMATION FILE_IO_COMPLETION_NOTIFICATION_INFORMATION;

typedef struct _FILE_IO_COMPLETION_NOTIFICATION_INFORMATION* PFILE_IO_COMPLETION_NOTIFICATION_INFORMATION;

enum _FSINFOCLASS
{
    _FSINFOCLASS_DUMMY = 0
};


typedef enum _FSINFOCLASS FS_INFORMATION_CLASS;

typedef enum _FSINFOCLASS* PFS_INFORMATION_CLASS;

enum _KEY_INFORMATION_CLASS
{
    _KEY_INFORMATION_CLASS_DUMMY = 0
};


typedef enum _KEY_INFORMATION_CLASS KEY_INFORMATION_CLASS;

enum _KEY_VALUE_INFORMATION_CLASS
{
    _KEY_VALUE_INFORMATION_CLASS_DUMMY = 0
};


typedef enum _KEY_VALUE_INFORMATION_CLASS KEY_VALUE_INFORMATION_CLASS;

enum _OBJECT_INFORMATION_CLASS
{
    _OBJECT_INFORMATION_CLASS_DUMMY = 0
};


typedef enum _OBJECT_INFORMATION_CLASS OBJECT_INFORMATION_CLASS;

typedef enum _OBJECT_INFORMATION_CLASS* POBJECT_INFORMATION_CLASS;

enum _PROCESSINFOCLASS
{
    _PROCESSINFOCLASS_DUMMY = 0
};


typedef enum _PROCESSINFOCLASS PROCESSINFOCLASS;

typedef enum _PROCESSINFOCLASS PROCESS_INFORMATION_CLASS;

enum _SECTION_INHERIT
{
    _SECTION_INHERIT_DUMMY = 0
};


typedef enum _SECTION_INHERIT SECTION_INHERIT;

enum _SYSTEM_INFORMATION_CLASS
{
    _SYSTEM_INFORMATION_CLASS_DUMMY = 0
};


typedef enum _SYSTEM_INFORMATION_CLASS SYSTEM_INFORMATION_CLASS;

typedef enum _SYSTEM_INFORMATION_CLASS* PSYSTEM_INFORMATION_CLASS;

enum _THREADINFOCLASS
{
    _THREADINFOCLASS_DUMMY = 0
};


typedef enum _THREADINFOCLASS THREADINFOCLASS;

struct _THREAD_BASIC_INFORMATION
{
    NTSTATUS ExitStatus;
    PVOID TebBaseAddress;
    CLIENT_ID ClientId;
    ULONG_PTR AffinityMask;
    LONG Priority;
    LONG BasePriority;
};


typedef struct _THREAD_BASIC_INFORMATION THREAD_BASIC_INFORMATION;

typedef struct _THREAD_BASIC_INFORMATION* PTHREAD_BASIC_INFORMATION;

struct _THREAD_DESCRIPTOR_INFORMATION
{
    DWORD Selector;
    LDT_ENTRY Entry;
};


typedef struct _THREAD_DESCRIPTOR_INFORMATION THREAD_DESCRIPTOR_INFORMATION;

typedef struct _THREAD_DESCRIPTOR_INFORMATION* PTHREAD_DESCRIPTOR_INFORMATION;

struct _KERNEL_USER_TIMES
{
    LARGE_INTEGER CreateTime;
    LARGE_INTEGER ExitTime;
    LARGE_INTEGER KernelTime;
    LARGE_INTEGER UserTime;
};


typedef struct _KERNEL_USER_TIMES KERNEL_USER_TIMES;

typedef struct _KERNEL_USER_TIMES* PKERNEL_USER_TIMES;

enum _WINSTATIONINFOCLASS
{
    _WINSTATIONINFOCLASS_DUMMY = 0
};


typedef enum _WINSTATIONINFOCLASS WINSTATIONINFOCLASS;

enum _MEMORY_INFORMATION_CLASS
{
    _MEMORY_INFORMATION_CLASS_DUMMY = 0
};


typedef enum _MEMORY_INFORMATION_CLASS MEMORY_INFORMATION_CLASS;

struct _MEMORY_SECTION_NAME
{
    UNICODE_STRING SectionFileName;
};


typedef struct _MEMORY_SECTION_NAME MEMORY_SECTION_NAME;

typedef struct _MEMORY_SECTION_NAME* PMEMORY_SECTION_NAME;

enum _MUTANT_INFORMATION_CLASS
{
    _MUTANT_INFORMATION_CLASS_DUMMY = 0
};


typedef enum _MUTANT_INFORMATION_CLASS MUTANT_INFORMATION_CLASS;

typedef enum _MUTANT_INFORMATION_CLASS* PMUTANT_INFORMATION_CLASS;

struct _MUTANT_BASIC_INFORMATION
{
    LONG CurrentCount;
    BOOLEAN OwnedByCaller;
    BOOLEAN AbandonedState;
};


typedef struct _MUTANT_BASIC_INFORMATION MUTANT_BASIC_INFORMATION;

typedef struct _MUTANT_BASIC_INFORMATION* PMUTANT_BASIC_INFORMATION;

enum _TIMER_INFORMATION_CLASS
{
    _TIMER_INFORMATION_CLASS_DUMMY = 0
};


typedef enum _TIMER_INFORMATION_CLASS TIMER_INFORMATION_CLASS;

struct _TIMER_BASIC_INFORMATION
{
    LARGE_INTEGER RemainingTime;
    BOOLEAN TimerState;
};


typedef struct _TIMER_BASIC_INFORMATION TIMER_BASIC_INFORMATION;

typedef struct _TIMER_BASIC_INFORMATION* PTIMER_BASIC_INFORMATION;

enum DOS_PATHNAME_TYPE
{
    DOS_PATHNAME_TYPE_DUMMY = 0
};


typedef enum DOS_PATHNAME_TYPE DOS_PATHNAME_TYPE;

struct _SYSTEM_THREAD_INFORMATION
{
    LARGE_INTEGER KernelTime;
    LARGE_INTEGER UserTime;
    LARGE_INTEGER CreateTime;
    DWORD dwTickCount;
    LPVOID StartAddress;
    CLIENT_ID ClientId;
    DWORD dwCurrentPriority;
    DWORD dwBasePriority;
    DWORD dwContextSwitches;
    DWORD dwThreadState;
    DWORD dwWaitReason;
    DWORD dwUnknown;
};


typedef struct _SYSTEM_THREAD_INFORMATION SYSTEM_THREAD_INFORMATION;

typedef struct _SYSTEM_THREAD_INFORMATION* PSYSTEM_THREAD_INFORMATION;

struct _IO_STATUS_BLOCK
{
    ULONG_PTR Information;
};


typedef struct _IO_STATUS_BLOCK IO_STATUS_BLOCK;

typedef struct _IO_STATUS_BLOCK* PIO_STATUS_BLOCK;

typedef void (*PIO_APC_ROUTINE) (PVOID, PIO_STATUS_BLOCK, ULONG);

struct _KEY_BASIC_INFORMATION
{
    LARGE_INTEGER LastWriteTime;
    ULONG TitleIndex;
    ULONG NameLength;
    WCHAR Name[1];
};


typedef struct _KEY_BASIC_INFORMATION KEY_BASIC_INFORMATION;

typedef struct _KEY_BASIC_INFORMATION* PKEY_BASIC_INFORMATION;

struct _KEY_NODE_INFORMATION
{
    LARGE_INTEGER LastWriteTime;
    ULONG TitleIndex;
    ULONG ClassOffset;
    ULONG ClassLength;
    ULONG NameLength;
    WCHAR Name[1];
};


typedef struct _KEY_NODE_INFORMATION KEY_NODE_INFORMATION;

typedef struct _KEY_NODE_INFORMATION* PKEY_NODE_INFORMATION;

struct _KEY_FULL_INFORMATION
{
    LARGE_INTEGER LastWriteTime;
    ULONG TitleIndex;
    ULONG ClassOffset;
    ULONG ClassLength;
    ULONG SubKeys;
    ULONG MaxNameLen;
    ULONG MaxClassLen;
    ULONG Values;
    ULONG MaxValueNameLen;
    ULONG MaxValueDataLen;
    WCHAR Class[1];
};


typedef struct _KEY_FULL_INFORMATION KEY_FULL_INFORMATION;

typedef struct _KEY_FULL_INFORMATION* PKEY_FULL_INFORMATION;

struct _KEY_NAME_INFORMATION
{
    ULONG NameLength;
    WCHAR Name[1];
};


typedef struct _KEY_NAME_INFORMATION KEY_NAME_INFORMATION;

typedef struct _KEY_NAME_INFORMATION* PKEY_NAME_INFORMATION;

struct _KEY_CACHED_INFORMATION
{
    LARGE_INTEGER LastWriteTime;
    ULONG TitleIndex;
    ULONG SubKeys;
    ULONG MaxNameLen;
    ULONG Values;
    ULONG MaxValueNameLen;
    ULONG MaxValueDataLen;
    ULONG NameLength;
};


typedef struct _KEY_CACHED_INFORMATION KEY_CACHED_INFORMATION;

typedef struct _KEY_CACHED_INFORMATION* PKEY_CACHED_INFORMATION;

struct _KEY_VALUE_ENTRY
{
    PUNICODE_STRING ValueName;
    ULONG DataLength;
    ULONG DataOffset;
    ULONG Type;
};


typedef struct _KEY_VALUE_ENTRY KEY_VALUE_ENTRY;

typedef struct _KEY_VALUE_ENTRY* PKEY_VALUE_ENTRY;

struct _KEY_VALUE_BASIC_INFORMATION
{
    ULONG TitleIndex;
    ULONG Type;
    ULONG NameLength;
    WCHAR Name[1];
};


typedef struct _KEY_VALUE_BASIC_INFORMATION KEY_VALUE_BASIC_INFORMATION;

typedef struct _KEY_VALUE_BASIC_INFORMATION* PKEY_VALUE_BASIC_INFORMATION;

struct _KEY_VALUE_FULL_INFORMATION
{
    ULONG TitleIndex;
    ULONG Type;
    ULONG DataOffset;
    ULONG DataLength;
    ULONG NameLength;
    WCHAR Name[1];
};


typedef struct _KEY_VALUE_FULL_INFORMATION KEY_VALUE_FULL_INFORMATION;

typedef struct _KEY_VALUE_FULL_INFORMATION* PKEY_VALUE_FULL_INFORMATION;

struct _KEY_VALUE_PARTIAL_INFORMATION
{
    ULONG TitleIndex;
    ULONG Type;
    ULONG DataLength;
    UCHAR Data[1];
};


typedef struct _KEY_VALUE_PARTIAL_INFORMATION KEY_VALUE_PARTIAL_INFORMATION;

typedef struct _KEY_VALUE_PARTIAL_INFORMATION* PKEY_VALUE_PARTIAL_INFORMATION;

struct _OBJECT_ATTRIBUTES
{
    ULONG Length;
    HANDLE RootDirectory;
    PUNICODE_STRING ObjectName;
    ULONG Attributes;
    PVOID SecurityDescriptor;
    PVOID SecurityQualityOfService;
};


typedef struct _OBJECT_ATTRIBUTES OBJECT_ATTRIBUTES;

typedef struct _OBJECT_ATTRIBUTES* POBJECT_ATTRIBUTES;

struct _OBJECT_DATA_INFORMATION
{
    BOOLEAN InheritHandle;
    BOOLEAN ProtectFromClose;
};


typedef struct _OBJECT_DATA_INFORMATION OBJECT_DATA_INFORMATION;

typedef struct _OBJECT_DATA_INFORMATION* POBJECT_DATA_INFORMATION;

struct _OBJECT_BASIC_INFORMATION
{
    ULONG Attributes;
    ACCESS_MASK GrantedAccess;
    ULONG HandleCount;
    ULONG PointerCount;
    ULONG PagedPoolUsage;
    ULONG NonPagedPoolUsage;
    ULONG Reserved[3];
    ULONG NameInformationLength;
    ULONG TypeInformationLength;
    ULONG SecurityDescriptorLength;
    LARGE_INTEGER CreateTime;
};


typedef struct _OBJECT_BASIC_INFORMATION OBJECT_BASIC_INFORMATION;

typedef struct _OBJECT_BASIC_INFORMATION* POBJECT_BASIC_INFORMATION;

struct _OBJECT_NAME_INFORMATION
{
    UNICODE_STRING Name;
};


typedef struct _OBJECT_NAME_INFORMATION OBJECT_NAME_INFORMATION;

typedef struct _OBJECT_NAME_INFORMATION* POBJECT_NAME_INFORMATION;

struct __OBJECT_TYPE_INFORMATION
{
    UNICODE_STRING TypeName;
    ULONG Reserved[22];
};


typedef struct __OBJECT_TYPE_INFORMATION OBJECT_TYPE_INFORMATION;

typedef struct __OBJECT_TYPE_INFORMATION* POBJECT_TYPE_INFORMATION;

struct _PROCESS_BASIC_INFORMATION
{
    DWORD_PTR ExitStatus;
    PPEB PebBaseAddress;
    DWORD_PTR AffinityMask;
    DWORD_PTR BasePriority;
    ULONG_PTR UniqueProcessId;
    ULONG_PTR InheritedFromUniqueProcessId;
};


typedef struct _PROCESS_BASIC_INFORMATION PROCESS_BASIC_INFORMATION;

typedef struct _PROCESS_BASIC_INFORMATION* PPROCESS_BASIC_INFORMATION;

struct _PROCESS_PRIORITY_CLASS
{
    BOOLEAN Foreground;
    UCHAR PriorityClass;
};


typedef struct _PROCESS_PRIORITY_CLASS PROCESS_PRIORITY_CLASS;

typedef struct _PROCESS_PRIORITY_CLASS* PPROCESS_PRIORITY_CLASS;

struct _RTL_HEAP_DEFINITION
{
    ULONG Length;
    ULONG Unknown[11];
};


typedef struct _RTL_HEAP_DEFINITION RTL_HEAP_DEFINITION;

typedef struct _RTL_HEAP_DEFINITION* PRTL_HEAP_DEFINITION;

struct _RTL_RWLOCK
{
    RTL_CRITICAL_SECTION rtlCS;
    HANDLE hSharedReleaseSemaphore;
    UINT uSharedWaiters;
    HANDLE hExclusiveReleaseSemaphore;
    UINT uExclusiveWaiters;
    INT iNumberActive;
    HANDLE hOwningThreadId;
    DWORD dwTimeoutBoost;
    PVOID pDebugInfo;
};


typedef struct _RTL_RWLOCK RTL_RWLOCK;

typedef struct _RTL_RWLOCK* LPRTL_RWLOCK;

struct _SYSTEM_BASIC_INFORMATION
{
    DWORD unknown;
    ULONG KeMaximumIncrement;
    ULONG PageSize;
    ULONG MmNumberOfPhysicalPages;
    ULONG MmLowestPhysicalPage;
    ULONG MmHighestPhysicalPage;
    ULONG_PTR AllocationGranularity;
    PVOID LowestUserAddress;
    PVOID HighestUserAddress;
    ULONG_PTR ActiveProcessorsAffinityMask;
    BYTE NumberOfProcessors;
};


typedef struct _SYSTEM_BASIC_INFORMATION SYSTEM_BASIC_INFORMATION;

typedef struct _SYSTEM_BASIC_INFORMATION* PSYSTEM_BASIC_INFORMATION;

struct _SYSTEM_CPU_INFORMATION
{
    WORD Architecture;
    WORD Level;
    WORD Revision;
    WORD Reserved;
    DWORD FeatureSet;
};


typedef struct _SYSTEM_CPU_INFORMATION SYSTEM_CPU_INFORMATION;

typedef struct _SYSTEM_CPU_INFORMATION* PSYSTEM_CPU_INFORMATION;

struct _SYSTEM_PERFORMANCE_INFORMATION
{
    LARGE_INTEGER IdleTime;
    LARGE_INTEGER ReadTransferCount;
    LARGE_INTEGER WriteTransferCount;
    LARGE_INTEGER OtherTransferCount;
    ULONG ReadOperationCount;
    ULONG WriteOperationCount;
    ULONG OtherOperationCount;
    ULONG AvailablePages;
    ULONG TotalCommittedPages;
    ULONG TotalCommitLimit;
    ULONG PeakCommitment;
    ULONG PageFaults;
    ULONG WriteCopyFaults;
    ULONG TransitionFaults;
    ULONG Reserved1;
    ULONG DemandZeroFaults;
    ULONG PagesRead;
    ULONG PageReadIos;
    ULONG Reserved2[2];
    ULONG PagefilePagesWritten;
    ULONG PagefilePageWriteIos;
    ULONG MappedFilePagesWritten;
    ULONG MappedFilePageWriteIos;
    ULONG PagedPoolUsage;
    ULONG NonPagedPoolUsage;
    ULONG PagedPoolAllocs;
    ULONG PagedPoolFrees;
    ULONG NonPagedPoolAllocs;
    ULONG NonPagedPoolFrees;
    ULONG TotalFreeSystemPtes;
    ULONG SystemCodePage;
    ULONG TotalSystemDriverPages;
    ULONG TotalSystemCodePages;
    ULONG SmallNonPagedLookasideListAllocateHits;
    ULONG SmallPagedLookasideListAllocateHits;
    ULONG Reserved3;
    ULONG MmSystemCachePage;
    ULONG PagedPoolPage;
    ULONG SystemDriverPage;
    ULONG FastReadNoWait;
    ULONG FastReadWait;
    ULONG FastReadResourceMiss;
    ULONG FastReadNotPossible;
    ULONG FastMdlReadNoWait;
    ULONG FastMdlReadWait;
    ULONG FastMdlReadResourceMiss;
    ULONG FastMdlReadNotPossible;
    ULONG MapDataNoWait;
    ULONG MapDataWait;
    ULONG MapDataNoWaitMiss;
    ULONG MapDataWaitMiss;
    ULONG PinMappedDataCount;
    ULONG PinReadNoWait;
    ULONG PinReadWait;
    ULONG PinReadNoWaitMiss;
    ULONG PinReadWaitMiss;
    ULONG CopyReadNoWait;
    ULONG CopyReadWait;
    ULONG CopyReadNoWaitMiss;
    ULONG CopyReadWaitMiss;
    ULONG MdlReadNoWait;
    ULONG MdlReadWait;
    ULONG MdlReadNoWaitMiss;
    ULONG MdlReadWaitMiss;
    ULONG ReadAheadIos;
    ULONG LazyWriteIos;
    ULONG LazyWritePages;
    ULONG DataFlushes;
    ULONG DataPages;
    ULONG ContextSwitches;
    ULONG FirstLevelTbFills;
    ULONG SecondLevelTbFills;
    ULONG SystemCalls;
};


typedef struct _SYSTEM_PERFORMANCE_INFORMATION SYSTEM_PERFORMANCE_INFORMATION;

typedef struct _SYSTEM_PERFORMANCE_INFORMATION* PSYSTEM_PERFORMANCE_INFORMATION;

struct _SYSTEM_TIMEOFDAY_INFORMATION
{
    LARGE_INTEGER liKeBootTime;
    LARGE_INTEGER liKeSystemTime;
    LARGE_INTEGER liExpTimeZoneBias;
    ULONG uCurrentTimeZoneId;
    DWORD dwUnknown1[5];
};


typedef struct _SYSTEM_TIMEOFDAY_INFORMATION SYSTEM_TIMEOFDAY_INFORMATION;

typedef struct _SYSTEM_TIMEOFDAY_INFORMATION* PSYSTEM_TIMEOFDAY_INFORMATION;

struct _SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION
{
    LARGE_INTEGER IdleTime;
    LARGE_INTEGER KernelTime;
    LARGE_INTEGER UserTime;
    LARGE_INTEGER Reserved1[2];
    ULONG Reserved2;
};


typedef struct _SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION;

typedef struct _SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION* PSYSTEM_PROCESSOR_PERFORMANCE_INFORMATION;

struct _SYSTEM_DRIVER_INFORMATION
{
    PVOID pvAddress;
    DWORD dwUnknown1;
    DWORD dwUnknown2;
    DWORD dwEntryIndex;
    DWORD dwUnknown3;
    char szName[261];
};


typedef struct _SYSTEM_DRIVER_INFORMATION SYSTEM_DRIVER_INFORMATION;

typedef struct _SYSTEM_DRIVER_INFORMATION* PSYSTEM_DRIVER_INFORMATION;

struct _SYSTEM_HANDLE_ENTRY
{
    ULONG OwnerPid;
    BYTE ObjectType;
    BYTE HandleFlags;
    USHORT HandleValue;
    PVOID ObjectPointer;
    ULONG AccessMask;
};


typedef struct _SYSTEM_HANDLE_ENTRY SYSTEM_HANDLE_ENTRY;

typedef struct _SYSTEM_HANDLE_ENTRY* PSYSTEM_HANDLE_ENTRY;

struct _SYSTEM_HANDLE_INFORMATION
{
    ULONG Count;
    SYSTEM_HANDLE_ENTRY Handle[1];
};


typedef struct _SYSTEM_HANDLE_INFORMATION SYSTEM_HANDLE_INFORMATION;

typedef struct _SYSTEM_HANDLE_INFORMATION* PSYSTEM_HANDLE_INFORMATION;

struct _SYSTEM_CACHE_INFORMATION
{
    ULONG CurrentSize;
    ULONG PeakSize;
    ULONG PageFaultCount;
    ULONG MinimumWorkingSet;
    ULONG MaximumWorkingSet;
    ULONG unused[4];
    ULONG unknown64[7];
};


typedef struct _SYSTEM_CACHE_INFORMATION SYSTEM_CACHE_INFORMATION;

typedef struct _SYSTEM_CACHE_INFORMATION* PSYSTEM_CACHE_INFORMATION;

struct _SYSTEM_INTERRUPT_INFORMATION
{
    BYTE Reserved1[24];
};


typedef struct _SYSTEM_INTERRUPT_INFORMATION SYSTEM_INTERRUPT_INFORMATION;

typedef struct _SYSTEM_INTERRUPT_INFORMATION* PSYSTEM_INTERRUPT_INFORMATION;

struct _SYSTEM_CONFIGURATION_INFO
{
    ULONG PageSize;
    PVOID MinimumApplicationAddress;
    PVOID MaximumApplicationAddress;
    ULONG ActiveProcessorMask;
    ULONG NumberOfProcessors;
    ULONG ProcessorType;
    ULONG AllocationGranularity;
    WORD ProcessorLevel;
    WORD ProcessorRevision;
};


typedef struct _SYSTEM_CONFIGURATION_INFO SYSTEM_CONFIGURATION_INFO;

typedef struct _SYSTEM_CONFIGURATION_INFO* PSYSTEM_CONFIGURATION_INFO;

struct _SYSTEM_EXCEPTION_INFORMATION
{
    BYTE Reserved1[16];
};


typedef struct _SYSTEM_EXCEPTION_INFORMATION SYSTEM_EXCEPTION_INFORMATION;

typedef struct _SYSTEM_EXCEPTION_INFORMATION* PSYSTEM_EXCEPTION_INFORMATION;

struct _SYSTEM_LOOKASIDE_INFORMATION
{
    BYTE Reserved1[32];
};


typedef struct _SYSTEM_LOOKASIDE_INFORMATION SYSTEM_LOOKASIDE_INFORMATION;

typedef struct _SYSTEM_LOOKASIDE_INFORMATION* PSYSTEM_LOOKASIDE_INFORMATION;

struct _SYSTEM_KERNEL_DEBUGGER_INFORMATION
{
    BOOLEAN DebuggerEnabled;
    BOOLEAN DebuggerNotPresent;
};


typedef struct _SYSTEM_KERNEL_DEBUGGER_INFORMATION SYSTEM_KERNEL_DEBUGGER_INFORMATION;

typedef struct _SYSTEM_KERNEL_DEBUGGER_INFORMATION* PSYSTEM_KERNEL_DEBUGGER_INFORMATION;

struct _VM_COUNTERS_
{
    SIZE_T PeakVirtualSize;
    SIZE_T VirtualSize;
    ULONG PageFaultCount;
    SIZE_T PeakWorkingSetSize;
    SIZE_T WorkingSetSize;
    SIZE_T QuotaPeakPagedPoolUsage;
    SIZE_T QuotaPagedPoolUsage;
    SIZE_T QuotaPeakNonPagedPoolUsage;
    SIZE_T QuotaNonPagedPoolUsage;
    SIZE_T PagefileUsage;
    SIZE_T PeakPagefileUsage;
    SIZE_T PrivatePageCount;
};


typedef struct _VM_COUNTERS_ VM_COUNTERS;

typedef struct _VM_COUNTERS_* PVM_COUNTERS;

struct _SYSTEM_PROCESS_INFORMATION
{
    ULONG NextEntryOffset;
    DWORD dwThreadCount;
    DWORD dwUnknown1[6];
    LARGE_INTEGER CreationTime;
    LARGE_INTEGER UserTime;
    LARGE_INTEGER KernelTime;
    UNICODE_STRING ProcessName;
    DWORD dwBasePriority;
    HANDLE UniqueProcessId;
    HANDLE ParentProcessId;
    ULONG HandleCount;
    ULONG SessionId;
    DWORD dwUnknown4;
    VM_COUNTERS vmCounters;
    IO_COUNTERS ioCounters;
    SYSTEM_THREAD_INFORMATION ti[1];
};


typedef struct _SYSTEM_PROCESS_INFORMATION SYSTEM_PROCESS_INFORMATION;

typedef struct _SYSTEM_PROCESS_INFORMATION* PSYSTEM_PROCESS_INFORMATION;

struct _SYSTEM_REGISTRY_QUOTA_INFORMATION
{
    ULONG RegistryQuotaAllowed;
    ULONG RegistryQuotaUsed;
    PVOID Reserved1;
};


typedef struct _SYSTEM_REGISTRY_QUOTA_INFORMATION SYSTEM_REGISTRY_QUOTA_INFORMATION;

typedef struct _SYSTEM_REGISTRY_QUOTA_INFORMATION* PSYSTEM_REGISTRY_QUOTA_INFORMATION;

struct _SYSTEM_TIME_ADJUSTMENT
{
    ULONG TimeAdjustment;
    BOOLEAN TimeAdjustmentDisabled;
};


typedef struct _SYSTEM_TIME_ADJUSTMENT SYSTEM_TIME_ADJUSTMENT;

typedef struct _SYSTEM_TIME_ADJUSTMENT* PSYSTEM_TIME_ADJUSTMENT;

enum _SYSTEM_FIRMWARE_TABLE_ACTION
{
    _SYSTEM_FIRMWARE_TABLE_ACTION_DUMMY = 0
};


typedef enum _SYSTEM_FIRMWARE_TABLE_ACTION SYSTEM_FIRMWARE_TABLE_ACTION;

typedef enum _SYSTEM_FIRMWARE_TABLE_ACTION* PSYSTEM_FIRMWARE_TABLE_ACTION;

struct _SYSTEM_FIRMWARE_TABLE_INFORMATION
{
    ULONG ProviderSignature;
    SYSTEM_FIRMWARE_TABLE_ACTION Action;
    ULONG TableID;
    ULONG TableBufferLength;
    UCHAR TableBuffer[1];
};


typedef struct _SYSTEM_FIRMWARE_TABLE_INFORMATION SYSTEM_FIRMWARE_TABLE_INFORMATION;

typedef struct _SYSTEM_FIRMWARE_TABLE_INFORMATION* PSYSTEM_FIRMWARE_TABLE_INFORMATION;

struct _TIME_FIELDS
{
    CSHORT Year;
    CSHORT Month;
    CSHORT Day;
    CSHORT Hour;
    CSHORT Minute;
    CSHORT Second;
    CSHORT Milliseconds;
    CSHORT Weekday;
};


typedef struct _TIME_FIELDS TIME_FIELDS;

typedef struct _TIME_FIELDS* PTIME_FIELDS;

struct _WINSTATIONINFORMATIONW
{
    BYTE Reserved2[70];
    ULONG LogonId;
    BYTE Reserved3[1140];
};


typedef struct _WINSTATIONINFORMATIONW WINSTATIONINFORMATIONW;

typedef struct _WINSTATIONINFORMATIONW* PWINSTATIONINFORMATIONW;

typedef BOOLEAN (*PWINSTATIONQUERYINFORMATIONW) (HANDLE, ULONG, WINSTATIONINFOCLASS, PVOID, ULONG, PULONG);

struct _LDR_RESOURCE_INFO
{
    ULONG_PTR Type;
    ULONG_PTR Name;
    ULONG Language;
};


typedef struct _LDR_RESOURCE_INFO LDR_RESOURCE_INFO;

typedef struct _LDR_RESOURCE_INFO* PLDR_RESOURCE_INFO;

struct _DEBUG_BUFFER
{
    HANDLE SectionHandle;
    PVOID SectionBase;
    PVOID RemoteSectionBase;
    ULONG SectionBaseDelta;
    HANDLE EventPairHandle;
    ULONG Unknown[2];
    HANDLE RemoteThreadHandle;
    ULONG InfoClassMask;
    ULONG SizeOfInfo;
    ULONG AllocatedSize;
    ULONG SectionSize;
    PVOID ModuleInformation;
    PVOID BackTraceInformation;
    PVOID HeapInformation;
    PVOID LockInformation;
    PVOID Reserved[8];
};


typedef struct _DEBUG_BUFFER DEBUG_BUFFER;

typedef struct _DEBUG_BUFFER* PDEBUG_BUFFER;

struct _DEBUG_MODULE_INFORMATION
{
    ULONG Reserved[2];
    ULONG Base;
    ULONG Size;
    ULONG Flags;
    USHORT Index;
    USHORT Unknown;
    USHORT LoadCount;
    USHORT ModuleNameOffset;
    CHAR ImageName[256];
};


typedef struct _DEBUG_MODULE_INFORMATION DEBUG_MODULE_INFORMATION;

typedef struct _DEBUG_MODULE_INFORMATION* PDEBUG_MODULE_INFORMATION;

struct _DEBUG_HEAP_INFORMATION
{
    ULONG Base;
    ULONG Flags;
    USHORT Granularity;
    USHORT Unknown;
    ULONG Allocated;
    ULONG Committed;
    ULONG TagCount;
    ULONG BlockCount;
    ULONG Reserved[7];
    PVOID Tags;
    PVOID Blocks;
};


typedef struct _DEBUG_HEAP_INFORMATION DEBUG_HEAP_INFORMATION;

typedef struct _DEBUG_HEAP_INFORMATION* PDEBUG_HEAP_INFORMATION;

struct _DEBUG_LOCK_INFORMATION
{
    PVOID Address;
    USHORT Type;
    USHORT CreatorBackTraceIndex;
    ULONG OwnerThreadId;
    ULONG ActiveCount;
    ULONG ContentionCount;
    ULONG EntryCount;
    ULONG RecursionCount;
    ULONG NumberOfSharedWaiters;
    ULONG NumberOfExclusiveWaiters;
};


typedef struct _DEBUG_LOCK_INFORMATION DEBUG_LOCK_INFORMATION;

typedef struct _DEBUG_LOCK_INFORMATION* PDEBUG_LOCK_INFORMATION;

struct _PORT_MESSAGE_HEADER
{
    USHORT DataSize;
    USHORT MessageSize;
    USHORT MessageType;
    USHORT VirtualRangesOffset;
    CLIENT_ID ClientId;
    ULONG MessageId;
    ULONG SectionSize;
};


typedef struct _PORT_MESSAGE_HEADER PORT_MESSAGE_HEADER;

typedef struct _PORT_MESSAGE_HEADER* PPORT_MESSAGE_HEADER;

typedef struct _PORT_MESSAGE_HEADER PORT_MESSAGE;

typedef struct _PORT_MESSAGE_HEADER* PPORT_MESSAGE;

typedef unsigned short RTL_ATOM;

typedef unsigned short* PRTL_ATOM;

typedef struct atom_table* RTL_ATOM_TABLE;

typedef struct atom_table** PRTL_ATOM_TABLE;

enum _ATOM_INFORMATION_CLASS
{
    _ATOM_INFORMATION_CLASS_DUMMY = 0
};


typedef enum _ATOM_INFORMATION_CLASS ATOM_INFORMATION_CLASS;

struct _ATOM_BASIC_INFORMATION
{
    USHORT ReferenceCount;
    USHORT Pinned;
    USHORT NameLength;
    WCHAR Name[1];
};


typedef struct _ATOM_BASIC_INFORMATION ATOM_BASIC_INFORMATION;

typedef struct _ATOM_BASIC_INFORMATION* PATOM_BASIC_INFORMATION;

struct _RTL_HANDLE
{
    struct _RTL_HANDLE* Next;
};


typedef struct _RTL_HANDLE RTL_HANDLE;

struct _RTL_HANDLE_TABLE
{
    ULONG MaxHandleCount;
    ULONG HandleSize;
    ULONG Unused[2];
    PVOID NextFree;
    PVOID FirstHandle;
    PVOID ReservedMemory;
    PVOID MaxHandle;
};


typedef struct _RTL_HANDLE_TABLE RTL_HANDLE_TABLE;

typedef void (*PNTAPCFUNC) (ULONG_PTR, ULONG_PTR, ULONG_PTR);

typedef void (*PRTL_THREAD_START_ROUTINE) (LPVOID);

typedef DWORD (*PRTL_WORK_ITEM_ROUTINE) (LPVOID);

typedef void (*RTL_WAITORTIMERCALLBACKFUNC) (PVOID, BOOLEAN);

typedef NTSTATUS (*PRTL_QUERY_REGISTRY_ROUTINE) (PCWSTR, ULONG, PVOID, ULONG, PVOID, PVOID);

struct _RTL_QUERY_REGISTRY_TABLE
{
    PRTL_QUERY_REGISTRY_ROUTINE QueryRoutine;
    ULONG Flags;
    PWSTR Name;
    PVOID EntryContext;
    ULONG DefaultType;
    PVOID DefaultData;
    ULONG DefaultLength;
};


typedef struct _RTL_QUERY_REGISTRY_TABLE RTL_QUERY_REGISTRY_TABLE;

typedef struct _RTL_QUERY_REGISTRY_TABLE* PRTL_QUERY_REGISTRY_TABLE;

struct _KEY_MULTIPLE_VALUE_INFORMATION
{
    PUNICODE_STRING ValueName;
    ULONG DataLength;
    ULONG DataOffset;
    ULONG Type;
};


typedef struct _KEY_MULTIPLE_VALUE_INFORMATION KEY_MULTIPLE_VALUE_INFORMATION;

typedef struct _KEY_MULTIPLE_VALUE_INFORMATION* PKEY_MULTIPLE_VALUE_INFORMATION;

typedef void (*PRTL_OVERLAPPED_COMPLETION_ROUTINE) (DWORD, DWORD, LPVOID);

typedef void (*PTIMER_APC_ROUTINE) (PVOID, ULONG, LONG);

enum _EVENT_INFORMATION_CLASS
{
    _EVENT_INFORMATION_CLASS_DUMMY = 0
};


typedef enum _EVENT_INFORMATION_CLASS EVENT_INFORMATION_CLASS;

typedef enum _EVENT_INFORMATION_CLASS* PEVENT_INFORMATION_CLASS;

struct _EVENT_BASIC_INFORMATION
{
    EVENT_TYPE EventType;
    LONG EventState;
};


typedef struct _EVENT_BASIC_INFORMATION EVENT_BASIC_INFORMATION;

typedef struct _EVENT_BASIC_INFORMATION* PEVENT_BASIC_INFORMATION;

enum _SEMAPHORE_INFORMATION_CLASS
{
    _SEMAPHORE_INFORMATION_CLASS_DUMMY = 0
};


typedef enum _SEMAPHORE_INFORMATION_CLASS SEMAPHORE_INFORMATION_CLASS;

typedef enum _SEMAPHORE_INFORMATION_CLASS* PSEMAPHORE_INFORMATION_CLASS;

struct _SEMAPHORE_BASIC_INFORMATION
{
    ULONG CurrentCount;
    ULONG MaximumCount;
};


typedef struct _SEMAPHORE_BASIC_INFORMATION SEMAPHORE_BASIC_INFORMATION;

typedef struct _SEMAPHORE_BASIC_INFORMATION* PSEMAPHORE_BASIC_INFORMATION;

enum _SECTION_INFORMATION_CLASS
{
    _SECTION_INFORMATION_CLASS_DUMMY = 0
};


typedef enum _SECTION_INFORMATION_CLASS SECTION_INFORMATION_CLASS;

struct _SECTION_BASIC_INFORMATION
{
    PVOID BaseAddress;
    ULONG Attributes;
    LARGE_INTEGER Size;
};


typedef struct _SECTION_BASIC_INFORMATION SECTION_BASIC_INFORMATION;

typedef struct _SECTION_BASIC_INFORMATION* PSECTION_BASIC_INFORMATION;

struct _SECTION_IMAGE_INFORMATION
{
    PVOID TransferAddress;
    ULONG ZeroBits;
    SIZE_T MaximumStackSize;
    SIZE_T CommittedStackSize;
    ULONG SubSystemType;
    WORD SubsystemVersionLow;
    WORD SubsystemVersionHigh;
    ULONG GpValue;
    USHORT ImageCharacteristics;
    USHORT DllCharacteristics;
    USHORT Machine;
    BOOLEAN ImageContainsCode;
    ULONG LoaderFlags;
    ULONG ImageFileSize;
    ULONG CheckSum;
};


typedef struct _SECTION_IMAGE_INFORMATION SECTION_IMAGE_INFORMATION;

typedef struct _SECTION_IMAGE_INFORMATION* PSECTION_IMAGE_INFORMATION;

struct _LPC_SECTION_WRITE
{
    ULONG Length;
    HANDLE SectionHandle;
    ULONG SectionOffset;
    ULONG ViewSize;
    PVOID ViewBase;
    PVOID TargetViewBase;
};


typedef struct _LPC_SECTION_WRITE LPC_SECTION_WRITE;

typedef struct _LPC_SECTION_WRITE* PLPC_SECTION_WRITE;

struct _LPC_SECTION_READ
{
    ULONG Length;
    ULONG ViewSize;
    PVOID ViewBase;
};


typedef struct _LPC_SECTION_READ LPC_SECTION_READ;

typedef struct _LPC_SECTION_READ* PLPC_SECTION_READ;

struct _LPC_MESSAGE
{
    USHORT DataSize;
    USHORT MessageSize;
    USHORT MessageType;
    USHORT VirtualRangesOffset;
    CLIENT_ID ClientId;
    ULONG_PTR MessageId;
    ULONG_PTR SectionSize;
    UCHAR Data[1];
};


typedef struct _LPC_MESSAGE LPC_MESSAGE;

typedef struct _LPC_MESSAGE* PLPC_MESSAGE;

struct _RTL_USER_PROCESS_INFORMATION
{
    ULONG Length;
    HANDLE Process;
    HANDLE Thread;
    CLIENT_ID ClientId;
    SECTION_IMAGE_INFORMATION ImageInformation;
};


typedef struct _RTL_USER_PROCESS_INFORMATION RTL_USER_PROCESS_INFORMATION;

typedef struct _RTL_USER_PROCESS_INFORMATION* PRTL_USER_PROCESS_INFORMATION;

enum _SHUTDOWN_ACTION
{
    _SHUTDOWN_ACTION_DUMMY = 0
};


typedef enum _SHUTDOWN_ACTION SHUTDOWN_ACTION;

typedef enum _SHUTDOWN_ACTION* PSHUTDOWN_ACTION;

struct _COUNTED_REASON_CONTEXT
{
    ULONG Version;
    ULONG Flags;
};


typedef struct _COUNTED_REASON_CONTEXT COUNTED_REASON_CONTEXT;

typedef struct _COUNTED_REASON_CONTEXT* PCOUNTED_REASON_CONTEXT;

enum _KPROFILE_SOURCE
{
    _KPROFILE_SOURCE_DUMMY = 0
};


typedef enum _KPROFILE_SOURCE KPROFILE_SOURCE;

typedef enum _KPROFILE_SOURCE* PKPROFILE_SOURCE;

struct _DIRECTORY_BASIC_INFORMATION
{
    UNICODE_STRING ObjectName;
    UNICODE_STRING ObjectTypeName;
};


typedef struct _DIRECTORY_BASIC_INFORMATION DIRECTORY_BASIC_INFORMATION;

typedef struct _DIRECTORY_BASIC_INFORMATION* PDIRECTORY_BASIC_INFORMATION;

struct _INITIAL_TEB
{
    void* OldStackBase;
    void* OldStackLimit;
    void* StackBase;
    void* StackLimit;
    void* DeallocationStack;
};


typedef struct _INITIAL_TEB INITIAL_TEB;

typedef struct _INITIAL_TEB* PINITIAL_TEB;

enum _PORT_INFORMATION_CLASS
{
    _PORT_INFORMATION_CLASS_DUMMY = 0
};


typedef enum _PORT_INFORMATION_CLASS PORT_INFORMATION_CLASS;

typedef enum _PORT_INFORMATION_CLASS* PPORT_INFORMATION_CLASS;

enum _IO_COMPLETION_INFORMATION_CLASS
{
    _IO_COMPLETION_INFORMATION_CLASS_DUMMY = 0
};


typedef enum _IO_COMPLETION_INFORMATION_CLASS IO_COMPLETION_INFORMATION_CLASS;

typedef enum _IO_COMPLETION_INFORMATION_CLASS* PIO_COMPLETION_INFORMATION_CLASS;

struct _FILE_COMPLETION_INFORMATION
{
    HANDLE CompletionPort;
    ULONG_PTR CompletionKey;
};


typedef struct _FILE_COMPLETION_INFORMATION FILE_COMPLETION_INFORMATION;

typedef struct _FILE_COMPLETION_INFORMATION* PFILE_COMPLETION_INFORMATION;

struct _FILE_IO_COMPLETION_INFORMATION
{
    ULONG_PTR CompletionKey;
    ULONG_PTR CompletionValue;
    IO_STATUS_BLOCK IoStatusBlock;
};


typedef struct _FILE_IO_COMPLETION_INFORMATION FILE_IO_COMPLETION_INFORMATION;

typedef struct _FILE_IO_COMPLETION_INFORMATION* PFILE_IO_COMPLETION_INFORMATION;

enum _HARDERROR_RESPONSE_OPTION
{
    _HARDERROR_RESPONSE_OPTION_DUMMY = 0
};


typedef enum _HARDERROR_RESPONSE_OPTION HARDERROR_RESPONSE_OPTION;

typedef enum _HARDERROR_RESPONSE_OPTION* PHARDERROR_RESPONSE_OPTION;

enum _HARDERROR_RESPONSE
{
    _HARDERROR_RESPONSE_DUMMY = 0
};


typedef enum _HARDERROR_RESPONSE HARDERROR_RESPONSE;

typedef enum _HARDERROR_RESPONSE* PHARDERROR_RESPONSE;

enum _SYSDBG_COMMAND
{
    _SYSDBG_COMMAND_DUMMY = 0
};


typedef enum _SYSDBG_COMMAND SYSDBG_COMMAND;

typedef enum _SYSDBG_COMMAND* PSYSDBG_COMMAND;

struct _LDR_MODULE
{
    LIST_ENTRY InLoadOrderModuleList;
    LIST_ENTRY InMemoryOrderModuleList;
    LIST_ENTRY InInitializationOrderModuleList;
    void* BaseAddress;
    void* EntryPoint;
    ULONG SizeOfImage;
    UNICODE_STRING FullDllName;
    UNICODE_STRING BaseDllName;
    ULONG Flags;
    SHORT LoadCount;
    SHORT TlsIndex;
    HANDLE SectionHandle;
    ULONG CheckSum;
    ULONG TimeDateStamp;
    HANDLE ActivationContext;
};


typedef struct _LDR_MODULE LDR_MODULE;

typedef struct _LDR_MODULE* PLDR_MODULE;

struct _LDR_DLL_LOADED_NOTIFICATION_DATA
{
    ULONG Flags;
    const UNICODE_STRING* FullDllName;
    const UNICODE_STRING* BaseDllName;
    void* DllBase;
    ULONG SizeOfImage;
};


typedef struct _LDR_DLL_LOADED_NOTIFICATION_DATA LDR_DLL_LOADED_NOTIFICATION_DATA;

typedef struct _LDR_DLL_LOADED_NOTIFICATION_DATA* PLDR_DLL_LOADED_NOTIFICATION_DATA;

struct _LDR_DLL_UNLOADED_NOTIFICATION_DATA
{
    ULONG Flags;
    const UNICODE_STRING* FullDllName;
    const UNICODE_STRING* BaseDllName;
    void* DllBase;
    ULONG SizeOfImage;
};


typedef struct _LDR_DLL_UNLOADED_NOTIFICATION_DATA LDR_DLL_UNLOADED_NOTIFICATION_DATA;

typedef struct _LDR_DLL_UNLOADED_NOTIFICATION_DATA* PLDR_DLL_UNLOADED_NOTIFICATION_DATA;

union _LDR_DLL_NOTIFICATION_DATA
{
    LDR_DLL_LOADED_NOTIFICATION_DATA Loaded;
    LDR_DLL_UNLOADED_NOTIFICATION_DATA Unloaded;
};


typedef union _LDR_DLL_NOTIFICATION_DATA LDR_DLL_NOTIFICATION_DATA;

typedef union _LDR_DLL_NOTIFICATION_DATA* PLDR_DLL_NOTIFICATION_DATA;

typedef void (*PLDR_DLL_NOTIFICATION_FUNCTION) (ULONG, LDR_DLL_NOTIFICATION_DATA*, void*);

struct _SYSTEM_MODULE
{
    PVOID Reserved1;
    PVOID Reserved2;
    PVOID ImageBaseAddress;
    ULONG ImageSize;
    ULONG Flags;
    WORD Id;
    WORD Rank;
    WORD Unknown;
    WORD NameOffset;
    BYTE Name[256];
};


typedef struct _SYSTEM_MODULE SYSTEM_MODULE;

typedef struct _SYSTEM_MODULE* PSYSTEM_MODULE;

struct _SYSTEM_MODULE_INFORMATION
{
    ULONG ModulesCount;
    SYSTEM_MODULE Modules[1];
};


typedef struct _SYSTEM_MODULE_INFORMATION SYSTEM_MODULE_INFORMATION;

typedef struct _SYSTEM_MODULE_INFORMATION* PSYSTEM_MODULE_INFORMATION;

typedef LONG (*PRTL_EXCEPTION_FILTER) (PEXCEPTION_POINTERS);

struct WIN16_SUBSYSTEM_TIB
{
    void* unknown;
    UNICODE_STRING* exe_name;
    UNICODE_STRING exe_str;
    CURDIR curdir;
    WCHAR curdir_buffer[260];
};


typedef struct WIN16_SUBSYSTEM_TIB WIN16_SUBSYSTEM_TIB;

typedef unsigned int obj_handle_t;

typedef unsigned int user_handle_t;

typedef unsigned int atom_t;

typedef unsigned int process_id_t;

typedef unsigned int thread_id_t;

typedef unsigned int data_size_t;

typedef unsigned int ioctl_code_t;

typedef unsigned long lparam_t;

typedef unsigned long apc_param_t;

typedef unsigned long mem_size_t;

typedef unsigned long file_pos_t;

typedef unsigned long client_ptr_t;

typedef unsigned long affinity_t;

typedef client_ptr_t mod_handle_t;

struct request_header
{
    int req;
    data_size_t request_size;
    data_size_t reply_size;
};


struct reply_header
{
    unsigned int error;
    data_size_t reply_size;
};


struct request_max_size
{
    int pad[16];
};


union debug_event_t
{
    int code;
};


typedef union debug_event_t debug_event_t;

enum cpu_type
{
    cpu_type_DUMMY = 0
};


typedef int client_cpu_t;

struct context_t
{
    client_cpu_t cpu;
    unsigned int flags;
};


typedef struct context_t context_t;

struct send_fd
{
    thread_id_t tid;
    int fd;
};


struct wake_up_reply
{
    client_ptr_t cookie;
    int signaled;
    int __pad;
};


typedef long timeout_t;

struct startup_info_t
{
    unsigned int debug_flags;
    unsigned int console_flags;
    obj_handle_t console;
    obj_handle_t hstdin;
    obj_handle_t hstdout;
    obj_handle_t hstderr;
    unsigned int x;
    unsigned int y;
    unsigned int xsize;
    unsigned int ysize;
    unsigned int xchars;
    unsigned int ychars;
    unsigned int attribute;
    unsigned int flags;
    unsigned int show;
    data_size_t curdir_len;
    data_size_t dllpath_len;
    data_size_t imagepath_len;
    data_size_t cmdline_len;
    data_size_t title_len;
    data_size_t desktop_len;
    data_size_t shellinfo_len;
    data_size_t runtime_len;
};


typedef struct startup_info_t startup_info_t;

struct property_data_t
{
    atom_t atom;
    int string;
    lparam_t data;
};


typedef struct property_data_t property_data_t;

struct rectangle_t
{
    int left;
    int top;
    int right;
    int bottom;
};


typedef struct rectangle_t rectangle_t;

struct async_data_t
{
    obj_handle_t handle;
    obj_handle_t event;
    client_ptr_t iosb;
    client_ptr_t user;
    client_ptr_t apc;
    apc_param_t apc_context;
};


typedef struct async_data_t async_data_t;

struct hw_msg_source
{
    unsigned int device;
    unsigned int origin;
};


struct hardware_msg_data
{
    lparam_t info;
    unsigned int hw_id;
    unsigned int flags;
    struct hw_msg_source source;
};


struct callback_msg_data
{
    client_ptr_t callback;
    lparam_t data;
    lparam_t result;
};


struct winevent_msg_data
{
    user_handle_t hook;
    thread_id_t tid;
    client_ptr_t hook_proc;
};


union hw_input_t
{
    int type;
};


typedef union hw_input_t hw_input_t;

union message_data_t
{
    unsigned char bytes[1];
    struct hardware_msg_data hardware;
    struct callback_msg_data callback;
    struct winevent_msg_data winevent;
};


typedef union message_data_t message_data_t;

struct char_info_t
{
    WCHAR ch;
    unsigned short attr;
};


typedef struct char_info_t char_info_t;

struct filesystem_event
{
    int action;
    data_size_t len;
    char name[1];
};


struct luid_t
{
    unsigned int low_part;
    int high_part;
};


typedef struct luid_t luid_t;

struct security_descriptor
{
    unsigned int control;
    data_size_t owner_len;
    data_size_t group_len;
    data_size_t sacl_len;
    data_size_t dacl_len;
};


struct object_attributes
{
    obj_handle_t rootdir;
    unsigned int attributes;
    data_size_t sd_len;
    data_size_t name_len;
};


struct token_groups
{
    unsigned int count;
};


enum select_op
{
    select_op_DUMMY = 0
};


union select_op_t
{
    enum select_op op;
};


typedef union select_op_t select_op_t;

enum apc_type
{
    apc_type_DUMMY = 0
};


union apc_call_t
{
    enum apc_type type;
};


typedef union apc_call_t apc_call_t;

union apc_result_t
{
    enum apc_type type;
};


typedef union apc_result_t apc_result_t;

enum irp_type
{
    irp_type_DUMMY = 0
};


union irp_params_t
{
    enum irp_type type;
};


typedef union irp_params_t irp_params_t;

struct pe_image_info_t
{
    client_ptr_t base;
    client_ptr_t entry_point;
    mem_size_t map_size;
    mem_size_t stack_size;
    mem_size_t stack_commit;
    unsigned int zerobits;
    unsigned int subsystem;
    unsigned short subsystem_low;
    unsigned short subsystem_high;
    unsigned int gp;
    unsigned short image_charact;
    unsigned short dll_charact;
    unsigned short machine;
    unsigned char contains_code;
    unsigned char image_flags;
    unsigned int loader_flags;
    unsigned int header_size;
    unsigned int file_size;
    unsigned int checksum;
    client_cpu_t cpu;
    int __pad;
};


typedef struct pe_image_info_t pe_image_info_t;

struct rawinput_device
{
    unsigned short usage_page;
    unsigned short usage;
    unsigned int flags;
    user_handle_t target;
};


struct new_process_request
{
    struct request_header __header;
    int inherit_all;
    unsigned int create_flags;
    int socket_fd;
    obj_handle_t exe_file;
    unsigned int access;
    client_cpu_t cpu;
    data_size_t info_size;
};


struct new_process_reply
{
    struct reply_header __header;
    obj_handle_t info;
    process_id_t pid;
    obj_handle_t handle;
    char __pad_20[4];
};


struct exec_process_request
{
    struct request_header __header;
    int socket_fd;
    obj_handle_t exe_file;
    client_cpu_t cpu;
};


struct exec_process_reply
{
    struct reply_header __header;
};


struct get_new_process_info_request
{
    struct request_header __header;
    obj_handle_t info;
};


struct get_new_process_info_reply
{
    struct reply_header __header;
    int success;
    int exit_code;
};


struct new_thread_request
{
    struct request_header __header;
    obj_handle_t process;
    unsigned int access;
    int suspend;
    int request_fd;
    char __pad_28[4];
};


struct new_thread_reply
{
    struct reply_header __header;
    thread_id_t tid;
    obj_handle_t handle;
};


struct get_startup_info_request
{
    struct request_header __header;
    char __pad_12[4];
};


struct get_startup_info_reply
{
    struct reply_header __header;
    data_size_t info_size;
    char __pad_12[4];
};


struct init_process_done_request
{
    struct request_header __header;
    int gui;
    mod_handle_t module;
    client_ptr_t ldt_copy;
    client_ptr_t entry;
};


struct init_process_done_reply
{
    struct reply_header __header;
    int suspend;
    char __pad_12[4];
};


struct init_thread_request
{
    struct request_header __header;
    int unix_pid;
    int unix_tid;
    int debug_level;
    client_ptr_t teb;
    client_ptr_t entry;
    int reply_fd;
    int wait_fd;
    client_cpu_t cpu;
    char __pad_52[4];
};


struct init_thread_reply
{
    struct reply_header __header;
    process_id_t pid;
    thread_id_t tid;
    timeout_t server_start;
    data_size_t info_size;
    int version;
    unsigned int all_cpus;
    int suspend;
};


struct terminate_process_request
{
    struct request_header __header;
    obj_handle_t handle;
    int exit_code;
    char __pad_20[4];
};


struct terminate_process_reply
{
    struct reply_header __header;
    int self;
    char __pad_12[4];
};


struct terminate_thread_request
{
    struct request_header __header;
    obj_handle_t handle;
    int exit_code;
    char __pad_20[4];
};


struct terminate_thread_reply
{
    struct reply_header __header;
    int self;
    int last;
};


struct get_process_info_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct get_process_info_reply
{
    struct reply_header __header;
    process_id_t pid;
    process_id_t ppid;
    affinity_t affinity;
    client_ptr_t peb;
    timeout_t start_time;
    timeout_t end_time;
    int exit_code;
    int priority;
    client_cpu_t cpu;
    short debugger_present;
    short debug_children;
};


struct get_process_vm_counters_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct get_process_vm_counters_reply
{
    struct reply_header __header;
    mem_size_t peak_virtual_size;
    mem_size_t virtual_size;
    mem_size_t peak_working_set_size;
    mem_size_t working_set_size;
    mem_size_t pagefile_usage;
    mem_size_t peak_pagefile_usage;
};


struct set_process_info_request
{
    struct request_header __header;
    obj_handle_t handle;
    int mask;
    int priority;
    affinity_t affinity;
};


struct set_process_info_reply
{
    struct reply_header __header;
};


struct get_thread_info_request
{
    struct request_header __header;
    obj_handle_t handle;
    thread_id_t tid_in;
    char __pad_20[4];
};


struct get_thread_info_reply
{
    struct reply_header __header;
    process_id_t pid;
    thread_id_t tid;
    client_ptr_t teb;
    client_ptr_t entry_point;
    affinity_t affinity;
    int exit_code;
    int priority;
    int last;
    char __pad_52[4];
};


struct get_thread_times_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct get_thread_times_reply
{
    struct reply_header __header;
    timeout_t creation_time;
    timeout_t exit_time;
};


struct set_thread_info_request
{
    struct request_header __header;
    obj_handle_t handle;
    int mask;
    int priority;
    affinity_t affinity;
    client_ptr_t entry_point;
    obj_handle_t token;
    char __pad_44[4];
};


struct set_thread_info_reply
{
    struct reply_header __header;
};


struct get_dll_info_request
{
    struct request_header __header;
    obj_handle_t handle;
    mod_handle_t base_address;
};


struct get_dll_info_reply
{
    struct reply_header __header;
    client_ptr_t entry_point;
    data_size_t filename_len;
    char __pad_20[4];
};


struct suspend_thread_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct suspend_thread_reply
{
    struct reply_header __header;
    int count;
    char __pad_12[4];
};


struct resume_thread_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct resume_thread_reply
{
    struct reply_header __header;
    int count;
    char __pad_12[4];
};


struct load_dll_request
{
    struct request_header __header;
    data_size_t dbg_offset;
    mod_handle_t base;
    client_ptr_t name;
    data_size_t dbg_size;
    char __pad_36[4];
};


struct load_dll_reply
{
    struct reply_header __header;
};


struct unload_dll_request
{
    struct request_header __header;
    char __pad_12[4];
    mod_handle_t base;
};


struct unload_dll_reply
{
    struct reply_header __header;
};


struct queue_apc_request
{
    struct request_header __header;
    obj_handle_t handle;
    apc_call_t call;
};


struct queue_apc_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    int self;
};


struct get_apc_result_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct get_apc_result_reply
{
    struct reply_header __header;
    apc_result_t result;
};


struct close_handle_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct close_handle_reply
{
    struct reply_header __header;
};


struct set_handle_info_request
{
    struct request_header __header;
    obj_handle_t handle;
    int flags;
    int mask;
};


struct set_handle_info_reply
{
    struct reply_header __header;
    int old_flags;
    char __pad_12[4];
};


struct dup_handle_request
{
    struct request_header __header;
    obj_handle_t src_process;
    obj_handle_t src_handle;
    obj_handle_t dst_process;
    unsigned int access;
    unsigned int attributes;
    unsigned int options;
    char __pad_36[4];
};


struct dup_handle_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    int self;
    int closed;
    char __pad_20[4];
};


struct open_process_request
{
    struct request_header __header;
    process_id_t pid;
    unsigned int access;
    unsigned int attributes;
};


struct open_process_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    char __pad_12[4];
};


struct open_thread_request
{
    struct request_header __header;
    thread_id_t tid;
    unsigned int access;
    unsigned int attributes;
};


struct open_thread_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    char __pad_12[4];
};


struct select_request
{
    struct request_header __header;
    int flags;
    client_ptr_t cookie;
    timeout_t timeout;
    obj_handle_t prev_apc;
    char __pad_36[4];
};


struct select_reply
{
    struct reply_header __header;
    timeout_t timeout;
    apc_call_t call;
    obj_handle_t apc_handle;
    char __pad_60[4];
};


struct create_event_request
{
    struct request_header __header;
    unsigned int access;
    int manual_reset;
    int initial_state;
};


struct create_event_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    char __pad_12[4];
};


struct event_op_request
{
    struct request_header __header;
    obj_handle_t handle;
    int op;
    char __pad_20[4];
};


struct event_op_reply
{
    struct reply_header __header;
    int state;
    char __pad_12[4];
};


enum event_op
{
    event_op_DUMMY = 0
};


struct query_event_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct query_event_reply
{
    struct reply_header __header;
    int manual_reset;
    int state;
};


struct open_event_request
{
    struct request_header __header;
    unsigned int access;
    unsigned int attributes;
    obj_handle_t rootdir;
};


struct open_event_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    char __pad_12[4];
};


struct create_keyed_event_request
{
    struct request_header __header;
    unsigned int access;
};


struct create_keyed_event_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    char __pad_12[4];
};


struct open_keyed_event_request
{
    struct request_header __header;
    unsigned int access;
    unsigned int attributes;
    obj_handle_t rootdir;
};


struct open_keyed_event_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    char __pad_12[4];
};


struct create_mutex_request
{
    struct request_header __header;
    unsigned int access;
    int owned;
    char __pad_20[4];
};


struct create_mutex_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    char __pad_12[4];
};


struct release_mutex_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct release_mutex_reply
{
    struct reply_header __header;
    unsigned int prev_count;
    char __pad_12[4];
};


struct open_mutex_request
{
    struct request_header __header;
    unsigned int access;
    unsigned int attributes;
    obj_handle_t rootdir;
};


struct open_mutex_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    char __pad_12[4];
};


struct query_mutex_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct query_mutex_reply
{
    struct reply_header __header;
    unsigned int count;
    int owned;
    int abandoned;
    char __pad_20[4];
};


struct create_semaphore_request
{
    struct request_header __header;
    unsigned int access;
    unsigned int initial;
    unsigned int max;
};


struct create_semaphore_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    char __pad_12[4];
};


struct release_semaphore_request
{
    struct request_header __header;
    obj_handle_t handle;
    unsigned int count;
    char __pad_20[4];
};


struct release_semaphore_reply
{
    struct reply_header __header;
    unsigned int prev_count;
    char __pad_12[4];
};


struct query_semaphore_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct query_semaphore_reply
{
    struct reply_header __header;
    unsigned int current;
    unsigned int max;
};


struct open_semaphore_request
{
    struct request_header __header;
    unsigned int access;
    unsigned int attributes;
    obj_handle_t rootdir;
};


struct open_semaphore_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    char __pad_12[4];
};


struct create_file_request
{
    struct request_header __header;
    unsigned int access;
    unsigned int sharing;
    int create;
    unsigned int options;
    unsigned int attrs;
};


struct create_file_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    char __pad_12[4];
};


struct open_file_object_request
{
    struct request_header __header;
    unsigned int access;
    unsigned int attributes;
    obj_handle_t rootdir;
    unsigned int sharing;
    unsigned int options;
};


struct open_file_object_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    char __pad_12[4];
};


struct alloc_file_handle_request
{
    struct request_header __header;
    unsigned int access;
    unsigned int attributes;
    int fd;
};


struct alloc_file_handle_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    char __pad_12[4];
};


struct get_handle_unix_name_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct get_handle_unix_name_reply
{
    struct reply_header __header;
    data_size_t name_len;
    char __pad_12[4];
};


struct get_handle_fd_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct get_handle_fd_reply
{
    struct reply_header __header;
    int type;
    int cacheable;
    unsigned int access;
    unsigned int options;
};


enum server_fd_type
{
    server_fd_type_DUMMY = 0
};


struct get_directory_cache_entry_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct get_directory_cache_entry_reply
{
    struct reply_header __header;
    int entry;
    char __pad_12[4];
};


struct flush_request
{
    struct request_header __header;
    char __pad_12[4];
    async_data_t async;
};


struct flush_reply
{
    struct reply_header __header;
    obj_handle_t event;
    char __pad_12[4];
};


struct get_file_info_request
{
    struct request_header __header;
    obj_handle_t handle;
    unsigned int info_class;
    char __pad_20[4];
};


struct get_file_info_reply
{
    struct reply_header __header;
};


struct get_volume_info_request
{
    struct request_header __header;
    obj_handle_t handle;
    unsigned int info_class;
    char __pad_20[4];
};


struct get_volume_info_reply
{
    struct reply_header __header;
};


struct lock_file_request
{
    struct request_header __header;
    obj_handle_t handle;
    file_pos_t offset;
    file_pos_t count;
    int shared;
    int wait;
};


struct lock_file_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    int overlapped;
};


struct unlock_file_request
{
    struct request_header __header;
    obj_handle_t handle;
    file_pos_t offset;
    file_pos_t count;
};


struct unlock_file_reply
{
    struct reply_header __header;
};


struct create_socket_request
{
    struct request_header __header;
    unsigned int access;
    unsigned int attributes;
    int family;
    int type;
    int protocol;
    unsigned int flags;
    char __pad_36[4];
};


struct create_socket_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    char __pad_12[4];
};


struct accept_socket_request
{
    struct request_header __header;
    obj_handle_t lhandle;
    unsigned int access;
    unsigned int attributes;
};


struct accept_socket_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    char __pad_12[4];
};


struct accept_into_socket_request
{
    struct request_header __header;
    obj_handle_t lhandle;
    obj_handle_t ahandle;
    char __pad_20[4];
};


struct accept_into_socket_reply
{
    struct reply_header __header;
};


struct set_socket_event_request
{
    struct request_header __header;
    obj_handle_t handle;
    unsigned int mask;
    obj_handle_t event;
    user_handle_t window;
    unsigned int msg;
};


struct set_socket_event_reply
{
    struct reply_header __header;
};


struct get_socket_event_request
{
    struct request_header __header;
    obj_handle_t handle;
    int service;
    obj_handle_t c_event;
};


struct get_socket_event_reply
{
    struct reply_header __header;
    unsigned int mask;
    unsigned int pmask;
    unsigned int state;
    char __pad_20[4];
};


struct get_socket_info_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct get_socket_info_reply
{
    struct reply_header __header;
    int family;
    int type;
    int protocol;
    char __pad_20[4];
};


struct enable_socket_event_request
{
    struct request_header __header;
    obj_handle_t handle;
    unsigned int mask;
    unsigned int sstate;
    unsigned int cstate;
    char __pad_28[4];
};


struct enable_socket_event_reply
{
    struct reply_header __header;
};


struct set_socket_deferred_request
{
    struct request_header __header;
    obj_handle_t handle;
    obj_handle_t deferred;
    char __pad_20[4];
};


struct set_socket_deferred_reply
{
    struct reply_header __header;
};


struct alloc_console_request
{
    struct request_header __header;
    unsigned int access;
    unsigned int attributes;
    process_id_t pid;
    int input_fd;
    char __pad_28[4];
};


struct alloc_console_reply
{
    struct reply_header __header;
    obj_handle_t handle_in;
    obj_handle_t event;
};


struct free_console_request
{
    struct request_header __header;
    char __pad_12[4];
};


struct free_console_reply
{
    struct reply_header __header;
};


struct console_renderer_event
{
    short event;
};


struct get_console_renderer_events_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct get_console_renderer_events_reply
{
    struct reply_header __header;
};


struct open_console_request
{
    struct request_header __header;
    obj_handle_t from;
    unsigned int access;
    unsigned int attributes;
    int share;
    char __pad_28[4];
};


struct open_console_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    char __pad_12[4];
};


struct attach_console_request
{
    struct request_header __header;
    process_id_t pid;
};


struct attach_console_reply
{
    struct reply_header __header;
    obj_handle_t std_in;
    obj_handle_t std_out;
    obj_handle_t std_err;
    char __pad_20[4];
};


struct get_console_wait_event_request
{
    struct request_header __header;
    char __pad_12[4];
};


struct get_console_wait_event_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    char __pad_12[4];
};


struct get_console_mode_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct get_console_mode_reply
{
    struct reply_header __header;
    int mode;
    char __pad_12[4];
};


struct set_console_mode_request
{
    struct request_header __header;
    obj_handle_t handle;
    int mode;
    char __pad_20[4];
};


struct set_console_mode_reply
{
    struct reply_header __header;
};


struct set_console_input_info_request
{
    struct request_header __header;
    obj_handle_t handle;
    int mask;
    obj_handle_t active_sb;
    int history_mode;
    int history_size;
    int edition_mode;
    int input_cp;
    int output_cp;
    user_handle_t win;
};


struct set_console_input_info_reply
{
    struct reply_header __header;
};


struct get_console_input_info_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct get_console_input_info_reply
{
    struct reply_header __header;
    int history_mode;
    int history_size;
    int history_index;
    int edition_mode;
    int input_cp;
    int output_cp;
    user_handle_t win;
    char __pad_36[4];
};


struct append_console_input_history_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct append_console_input_history_reply
{
    struct reply_header __header;
};


struct get_console_input_history_request
{
    struct request_header __header;
    obj_handle_t handle;
    int index;
    char __pad_20[4];
};


struct get_console_input_history_reply
{
    struct reply_header __header;
    int total;
    char __pad_12[4];
};


struct create_console_output_request
{
    struct request_header __header;
    obj_handle_t handle_in;
    unsigned int access;
    unsigned int attributes;
    unsigned int share;
    int fd;
};


struct create_console_output_reply
{
    struct reply_header __header;
    obj_handle_t handle_out;
    char __pad_12[4];
};


struct set_console_output_info_request
{
    struct request_header __header;
    obj_handle_t handle;
    int mask;
    short cursor_size;
    short cursor_visible;
    short cursor_x;
    short cursor_y;
    short width;
    short height;
    short attr;
    short popup_attr;
    short win_left;
    short win_top;
    short win_right;
    short win_bottom;
    short max_width;
    short max_height;
    short font_width;
    short font_height;
    char __pad_52[4];
};


struct set_console_output_info_reply
{
    struct reply_header __header;
};


struct get_console_output_info_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct get_console_output_info_reply
{
    struct reply_header __header;
    short cursor_size;
    short cursor_visible;
    short cursor_x;
    short cursor_y;
    short width;
    short height;
    short attr;
    short popup_attr;
    short win_left;
    short win_top;
    short win_right;
    short win_bottom;
    short max_width;
    short max_height;
    short font_width;
    short font_height;
};


struct write_console_input_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct write_console_input_reply
{
    struct reply_header __header;
    int written;
    char __pad_12[4];
};


struct read_console_input_request
{
    struct request_header __header;
    obj_handle_t handle;
    int flush;
    char __pad_20[4];
};


struct read_console_input_reply
{
    struct reply_header __header;
    int read;
    char __pad_12[4];
};


struct write_console_output_request
{
    struct request_header __header;
    obj_handle_t handle;
    int x;
    int y;
    int mode;
    int wrap;
};


struct write_console_output_reply
{
    struct reply_header __header;
    int written;
    int width;
    int height;
    char __pad_20[4];
};


enum char_info_mode
{
    char_info_mode_DUMMY = 0
};


struct fill_console_output_request
{
    struct request_header __header;
    obj_handle_t handle;
    int x;
    int y;
    int mode;
    int count;
    int wrap;
    char_info_t data;
};


struct fill_console_output_reply
{
    struct reply_header __header;
    int written;
    char __pad_12[4];
};


struct read_console_output_request
{
    struct request_header __header;
    obj_handle_t handle;
    int x;
    int y;
    int mode;
    int wrap;
};


struct read_console_output_reply
{
    struct reply_header __header;
    int width;
    int height;
};


struct move_console_output_request
{
    struct request_header __header;
    obj_handle_t handle;
    short x_src;
    short y_src;
    short x_dst;
    short y_dst;
    short w;
    short h;
    char __pad_28[4];
};


struct move_console_output_reply
{
    struct reply_header __header;
};


struct send_console_signal_request
{
    struct request_header __header;
    int signal;
    process_id_t group_id;
    char __pad_20[4];
};


struct send_console_signal_reply
{
    struct reply_header __header;
};


struct read_directory_changes_request
{
    struct request_header __header;
    unsigned int filter;
    int subtree;
    int want_data;
    async_data_t async;
};


struct read_directory_changes_reply
{
    struct reply_header __header;
};


struct read_change_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct read_change_reply
{
    struct reply_header __header;
};


struct create_mapping_request
{
    struct request_header __header;
    unsigned int access;
    unsigned int flags;
    unsigned int file_access;
    mem_size_t size;
    obj_handle_t file_handle;
    char __pad_36[4];
};


struct create_mapping_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    char __pad_12[4];
};


struct open_mapping_request
{
    struct request_header __header;
    unsigned int access;
    unsigned int attributes;
    obj_handle_t rootdir;
};


struct open_mapping_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    char __pad_12[4];
};


struct get_mapping_info_request
{
    struct request_header __header;
    obj_handle_t handle;
    unsigned int access;
    char __pad_20[4];
};


struct get_mapping_info_reply
{
    struct reply_header __header;
    mem_size_t size;
    unsigned int flags;
    obj_handle_t shared_file;
};


struct map_view_request
{
    struct request_header __header;
    obj_handle_t mapping;
    unsigned int access;
    char __pad_20[4];
    client_ptr_t base;
    mem_size_t size;
    file_pos_t start;
};


struct map_view_reply
{
    struct reply_header __header;
};


struct unmap_view_request
{
    struct request_header __header;
    char __pad_12[4];
    client_ptr_t base;
};


struct unmap_view_reply
{
    struct reply_header __header;
};


struct get_mapping_committed_range_request
{
    struct request_header __header;
    char __pad_12[4];
    client_ptr_t base;
    file_pos_t offset;
};


struct get_mapping_committed_range_reply
{
    struct reply_header __header;
    mem_size_t size;
    int committed;
    char __pad_20[4];
};


struct add_mapping_committed_range_request
{
    struct request_header __header;
    char __pad_12[4];
    client_ptr_t base;
    file_pos_t offset;
    mem_size_t size;
};


struct add_mapping_committed_range_reply
{
    struct reply_header __header;
};


struct is_same_mapping_request
{
    struct request_header __header;
    char __pad_12[4];
    client_ptr_t base1;
    client_ptr_t base2;
};


struct is_same_mapping_reply
{
    struct reply_header __header;
};


struct create_snapshot_request
{
    struct request_header __header;
    unsigned int attributes;
    unsigned int flags;
    char __pad_20[4];
};


struct create_snapshot_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    char __pad_12[4];
};


struct next_process_request
{
    struct request_header __header;
    obj_handle_t handle;
    int reset;
    char __pad_20[4];
};


struct next_process_reply
{
    struct reply_header __header;
    int count;
    process_id_t pid;
    process_id_t ppid;
    int threads;
    int priority;
    int handles;
    int unix_pid;
    char __pad_36[4];
};


struct next_thread_request
{
    struct request_header __header;
    obj_handle_t handle;
    int reset;
    char __pad_20[4];
};


struct next_thread_reply
{
    struct reply_header __header;
    int count;
    process_id_t pid;
    thread_id_t tid;
    int base_pri;
    int delta_pri;
    char __pad_28[4];
};


struct wait_debug_event_request
{
    struct request_header __header;
    int get_handle;
};


struct wait_debug_event_reply
{
    struct reply_header __header;
    process_id_t pid;
    thread_id_t tid;
    obj_handle_t wait;
    char __pad_20[4];
};


struct queue_exception_event_request
{
    struct request_header __header;
    int first;
    unsigned int code;
    unsigned int flags;
    client_ptr_t record;
    client_ptr_t address;
    data_size_t len;
    char __pad_44[4];
};


struct queue_exception_event_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    char __pad_12[4];
};


struct get_exception_status_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct get_exception_status_reply
{
    struct reply_header __header;
};


struct continue_debug_event_request
{
    struct request_header __header;
    process_id_t pid;
    thread_id_t tid;
    int status;
};


struct continue_debug_event_reply
{
    struct reply_header __header;
};


struct debug_process_request
{
    struct request_header __header;
    process_id_t pid;
    int attach;
    char __pad_20[4];
};


struct debug_process_reply
{
    struct reply_header __header;
};


struct set_debugger_kill_on_exit_request
{
    struct request_header __header;
    int kill_on_exit;
};


struct set_debugger_kill_on_exit_reply
{
    struct reply_header __header;
};


struct read_process_memory_request
{
    struct request_header __header;
    obj_handle_t handle;
    client_ptr_t addr;
};


struct read_process_memory_reply
{
    struct reply_header __header;
};


struct write_process_memory_request
{
    struct request_header __header;
    obj_handle_t handle;
    client_ptr_t addr;
};


struct write_process_memory_reply
{
    struct reply_header __header;
};


struct create_key_request
{
    struct request_header __header;
    unsigned int access;
    unsigned int options;
    char __pad_20[4];
};


struct create_key_reply
{
    struct reply_header __header;
    obj_handle_t hkey;
    int created;
};


struct open_key_request
{
    struct request_header __header;
    obj_handle_t parent;
    unsigned int access;
    unsigned int attributes;
};


struct open_key_reply
{
    struct reply_header __header;
    obj_handle_t hkey;
    char __pad_12[4];
};


struct delete_key_request
{
    struct request_header __header;
    obj_handle_t hkey;
};


struct delete_key_reply
{
    struct reply_header __header;
};


struct flush_key_request
{
    struct request_header __header;
    obj_handle_t hkey;
};


struct flush_key_reply
{
    struct reply_header __header;
};


struct enum_key_request
{
    struct request_header __header;
    obj_handle_t hkey;
    int index;
    int info_class;
};


struct enum_key_reply
{
    struct reply_header __header;
    int subkeys;
    int max_subkey;
    int max_class;
    int values;
    int max_value;
    int max_data;
    timeout_t modif;
    data_size_t total;
    data_size_t namelen;
};


struct set_key_value_request
{
    struct request_header __header;
    obj_handle_t hkey;
    int type;
    data_size_t namelen;
};


struct set_key_value_reply
{
    struct reply_header __header;
};


struct get_key_value_request
{
    struct request_header __header;
    obj_handle_t hkey;
};


struct get_key_value_reply
{
    struct reply_header __header;
    int type;
    data_size_t total;
};


struct enum_key_value_request
{
    struct request_header __header;
    obj_handle_t hkey;
    int index;
    int info_class;
};


struct enum_key_value_reply
{
    struct reply_header __header;
    int type;
    data_size_t total;
    data_size_t namelen;
    char __pad_20[4];
};


struct delete_key_value_request
{
    struct request_header __header;
    obj_handle_t hkey;
};


struct delete_key_value_reply
{
    struct reply_header __header;
};


struct load_registry_request
{
    struct request_header __header;
    obj_handle_t file;
};


struct load_registry_reply
{
    struct reply_header __header;
};


struct unload_registry_request
{
    struct request_header __header;
    obj_handle_t hkey;
};


struct unload_registry_reply
{
    struct reply_header __header;
};


struct save_registry_request
{
    struct request_header __header;
    obj_handle_t hkey;
    obj_handle_t file;
    char __pad_20[4];
};


struct save_registry_reply
{
    struct reply_header __header;
};


struct set_registry_notification_request
{
    struct request_header __header;
    obj_handle_t hkey;
    obj_handle_t event;
    int subtree;
    unsigned int filter;
    char __pad_28[4];
};


struct set_registry_notification_reply
{
    struct reply_header __header;
};


struct create_timer_request
{
    struct request_header __header;
    unsigned int access;
    int manual;
    char __pad_20[4];
};


struct create_timer_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    char __pad_12[4];
};


struct open_timer_request
{
    struct request_header __header;
    unsigned int access;
    unsigned int attributes;
    obj_handle_t rootdir;
};


struct open_timer_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    char __pad_12[4];
};


struct set_timer_request
{
    struct request_header __header;
    obj_handle_t handle;
    timeout_t expire;
    client_ptr_t callback;
    client_ptr_t arg;
    int period;
    char __pad_44[4];
};


struct set_timer_reply
{
    struct reply_header __header;
    int signaled;
    char __pad_12[4];
};


struct cancel_timer_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct cancel_timer_reply
{
    struct reply_header __header;
    int signaled;
    char __pad_12[4];
};


struct get_timer_info_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct get_timer_info_reply
{
    struct reply_header __header;
    timeout_t when;
    int signaled;
    char __pad_20[4];
};


struct get_thread_context_request
{
    struct request_header __header;
    obj_handle_t handle;
    unsigned int flags;
    int suspend;
};


struct get_thread_context_reply
{
    struct reply_header __header;
    int self;
    char __pad_12[4];
};


struct set_thread_context_request
{
    struct request_header __header;
    obj_handle_t handle;
    int suspend;
    char __pad_20[4];
};


struct set_thread_context_reply
{
    struct reply_header __header;
    int self;
    char __pad_12[4];
};


struct get_selector_entry_request
{
    struct request_header __header;
    obj_handle_t handle;
    int entry;
    char __pad_20[4];
};


struct get_selector_entry_reply
{
    struct reply_header __header;
    unsigned int base;
    unsigned int limit;
    unsigned char flags;
    char __pad_17[7];
};


struct add_atom_request
{
    struct request_header __header;
    obj_handle_t table;
};


struct add_atom_reply
{
    struct reply_header __header;
    atom_t atom;
    char __pad_12[4];
};


struct delete_atom_request
{
    struct request_header __header;
    obj_handle_t table;
    atom_t atom;
    char __pad_20[4];
};


struct delete_atom_reply
{
    struct reply_header __header;
};


struct find_atom_request
{
    struct request_header __header;
    obj_handle_t table;
};


struct find_atom_reply
{
    struct reply_header __header;
    atom_t atom;
    char __pad_12[4];
};


struct get_atom_information_request
{
    struct request_header __header;
    obj_handle_t table;
    atom_t atom;
    char __pad_20[4];
};


struct get_atom_information_reply
{
    struct reply_header __header;
    int count;
    int pinned;
    data_size_t total;
    char __pad_20[4];
};


struct set_atom_information_request
{
    struct request_header __header;
    obj_handle_t table;
    atom_t atom;
    int pinned;
};


struct set_atom_information_reply
{
    struct reply_header __header;
};


struct empty_atom_table_request
{
    struct request_header __header;
    obj_handle_t table;
    int if_pinned;
    char __pad_20[4];
};


struct empty_atom_table_reply
{
    struct reply_header __header;
};


struct init_atom_table_request
{
    struct request_header __header;
    int entries;
};


struct init_atom_table_reply
{
    struct reply_header __header;
    obj_handle_t table;
    char __pad_12[4];
};


struct get_msg_queue_request
{
    struct request_header __header;
    char __pad_12[4];
};


struct get_msg_queue_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    char __pad_12[4];
};


struct set_queue_fd_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct set_queue_fd_reply
{
    struct reply_header __header;
};


struct set_queue_mask_request
{
    struct request_header __header;
    unsigned int wake_mask;
    unsigned int changed_mask;
    int skip_wait;
};


struct set_queue_mask_reply
{
    struct reply_header __header;
    unsigned int wake_bits;
    unsigned int changed_bits;
};


struct get_queue_status_request
{
    struct request_header __header;
    unsigned int clear_bits;
};


struct get_queue_status_reply
{
    struct reply_header __header;
    unsigned int wake_bits;
    unsigned int changed_bits;
};


struct get_process_idle_event_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct get_process_idle_event_reply
{
    struct reply_header __header;
    obj_handle_t event;
    char __pad_12[4];
};


struct send_message_request
{
    struct request_header __header;
    thread_id_t id;
    int type;
    int flags;
    user_handle_t win;
    unsigned int msg;
    lparam_t wparam;
    lparam_t lparam;
    timeout_t timeout;
};


struct send_message_reply
{
    struct reply_header __header;
};


struct post_quit_message_request
{
    struct request_header __header;
    int exit_code;
};


struct post_quit_message_reply
{
    struct reply_header __header;
};


enum message_type
{
    message_type_DUMMY = 0
};


struct send_hardware_message_request
{
    struct request_header __header;
    user_handle_t win;
    hw_input_t input;
    unsigned int flags;
    char __pad_52[4];
};


struct send_hardware_message_reply
{
    struct reply_header __header;
    int wait;
    int prev_x;
    int prev_y;
    int new_x;
    int new_y;
    char __pad_28[4];
};


struct get_message_request
{
    struct request_header __header;
    unsigned int flags;
    user_handle_t get_win;
    unsigned int get_first;
    unsigned int get_last;
    unsigned int hw_id;
    unsigned int wake_mask;
    unsigned int changed_mask;
};


struct get_message_reply
{
    struct reply_header __header;
    user_handle_t win;
    unsigned int msg;
    lparam_t wparam;
    lparam_t lparam;
    int type;
    int x;
    int y;
    unsigned int time;
    unsigned int active_hooks;
    data_size_t total;
};


struct reply_message_request
{
    struct request_header __header;
    int remove;
    lparam_t result;
};


struct reply_message_reply
{
    struct reply_header __header;
};


struct accept_hardware_message_request
{
    struct request_header __header;
    unsigned int hw_id;
    int remove;
    char __pad_20[4];
};


struct accept_hardware_message_reply
{
    struct reply_header __header;
};


struct get_message_reply_request
{
    struct request_header __header;
    int cancel;
};


struct get_message_reply_reply
{
    struct reply_header __header;
    lparam_t result;
};


struct set_win_timer_request
{
    struct request_header __header;
    user_handle_t win;
    unsigned int msg;
    unsigned int rate;
    lparam_t id;
    lparam_t lparam;
};


struct set_win_timer_reply
{
    struct reply_header __header;
    lparam_t id;
};


struct kill_win_timer_request
{
    struct request_header __header;
    user_handle_t win;
    lparam_t id;
    unsigned int msg;
    char __pad_28[4];
};


struct kill_win_timer_reply
{
    struct reply_header __header;
};


struct is_window_hung_request
{
    struct request_header __header;
    user_handle_t win;
};


struct is_window_hung_reply
{
    struct reply_header __header;
    int is_hung;
    char __pad_12[4];
};


struct get_serial_info_request
{
    struct request_header __header;
    obj_handle_t handle;
    int flags;
    char __pad_20[4];
};


struct get_serial_info_reply
{
    struct reply_header __header;
    unsigned int eventmask;
    unsigned int cookie;
    unsigned int pending_write;
    char __pad_20[4];
};


struct set_serial_info_request
{
    struct request_header __header;
    obj_handle_t handle;
    int flags;
    char __pad_20[4];
};


struct set_serial_info_reply
{
    struct reply_header __header;
};


struct register_async_request
{
    struct request_header __header;
    int type;
    async_data_t async;
    int count;
    char __pad_60[4];
};


struct register_async_reply
{
    struct reply_header __header;
};


struct cancel_async_request
{
    struct request_header __header;
    obj_handle_t handle;
    client_ptr_t iosb;
    int only_thread;
    char __pad_28[4];
};


struct cancel_async_reply
{
    struct reply_header __header;
};


struct get_async_result_request
{
    struct request_header __header;
    char __pad_12[4];
    client_ptr_t user_arg;
};


struct get_async_result_reply
{
    struct reply_header __header;
    data_size_t size;
    char __pad_12[4];
};


struct read_request
{
    struct request_header __header;
    char __pad_12[4];
    async_data_t async;
    file_pos_t pos;
};


struct read_reply
{
    struct reply_header __header;
    obj_handle_t wait;
    unsigned int options;
};


struct write_request
{
    struct request_header __header;
    char __pad_12[4];
    async_data_t async;
    file_pos_t pos;
};


struct write_reply
{
    struct reply_header __header;
    obj_handle_t wait;
    unsigned int options;
    data_size_t size;
    char __pad_20[4];
};


struct ioctl_request
{
    struct request_header __header;
    ioctl_code_t code;
    async_data_t async;
};


struct ioctl_reply
{
    struct reply_header __header;
    obj_handle_t wait;
    unsigned int options;
};


struct set_irp_result_request
{
    struct request_header __header;
    obj_handle_t handle;
    unsigned int status;
    data_size_t size;
};


struct set_irp_result_reply
{
    struct reply_header __header;
};


struct create_named_pipe_request
{
    struct request_header __header;
    unsigned int access;
    unsigned int options;
    unsigned int sharing;
    unsigned int maxinstances;
    unsigned int outsize;
    unsigned int insize;
    char __pad_36[4];
    timeout_t timeout;
    unsigned int flags;
    char __pad_52[4];
};


struct create_named_pipe_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    char __pad_12[4];
};


struct set_named_pipe_info_request
{
    struct request_header __header;
    obj_handle_t handle;
    unsigned int flags;
    char __pad_20[4];
};


struct set_named_pipe_info_reply
{
    struct reply_header __header;
};


struct create_window_request
{
    struct request_header __header;
    user_handle_t parent;
    user_handle_t owner;
    atom_t atom;
    mod_handle_t instance;
    int dpi;
    int awareness;
};


struct create_window_reply
{
    struct reply_header __header;
    user_handle_t handle;
    user_handle_t parent;
    user_handle_t owner;
    int extra;
    client_ptr_t class_ptr;
    int dpi;
    int awareness;
};


struct destroy_window_request
{
    struct request_header __header;
    user_handle_t handle;
};


struct destroy_window_reply
{
    struct reply_header __header;
};


struct get_desktop_window_request
{
    struct request_header __header;
    int force;
};


struct get_desktop_window_reply
{
    struct reply_header __header;
    user_handle_t top_window;
    user_handle_t msg_window;
};


struct set_window_owner_request
{
    struct request_header __header;
    user_handle_t handle;
    user_handle_t owner;
    char __pad_20[4];
};


struct set_window_owner_reply
{
    struct reply_header __header;
    user_handle_t full_owner;
    user_handle_t prev_owner;
};


struct get_window_info_request
{
    struct request_header __header;
    user_handle_t handle;
};


struct get_window_info_reply
{
    struct reply_header __header;
    user_handle_t full_handle;
    user_handle_t last_active;
    process_id_t pid;
    thread_id_t tid;
    atom_t atom;
    int is_unicode;
    int dpi;
    int awareness;
};


struct set_window_info_request
{
    struct request_header __header;
    unsigned short flags;
    short is_unicode;
    user_handle_t handle;
    unsigned int style;
    unsigned int ex_style;
    unsigned int id;
    mod_handle_t instance;
    lparam_t user_data;
    int extra_offset;
    data_size_t extra_size;
    lparam_t extra_value;
};


struct set_window_info_reply
{
    struct reply_header __header;
    unsigned int old_style;
    unsigned int old_ex_style;
    mod_handle_t old_instance;
    lparam_t old_user_data;
    lparam_t old_extra_value;
    unsigned int old_id;
    char __pad_44[4];
};


struct set_parent_request
{
    struct request_header __header;
    user_handle_t handle;
    user_handle_t parent;
    char __pad_20[4];
};


struct set_parent_reply
{
    struct reply_header __header;
    user_handle_t old_parent;
    user_handle_t full_parent;
    int dpi;
    int awareness;
};


struct get_window_parents_request
{
    struct request_header __header;
    user_handle_t handle;
};


struct get_window_parents_reply
{
    struct reply_header __header;
    int count;
    char __pad_12[4];
};


struct get_window_children_request
{
    struct request_header __header;
    obj_handle_t desktop;
    user_handle_t parent;
    atom_t atom;
    thread_id_t tid;
    char __pad_28[4];
};


struct get_window_children_reply
{
    struct reply_header __header;
    int count;
    char __pad_12[4];
};


struct get_window_children_from_point_request
{
    struct request_header __header;
    user_handle_t parent;
    int x;
    int y;
    int dpi;
    char __pad_28[4];
};


struct get_window_children_from_point_reply
{
    struct reply_header __header;
    int count;
    char __pad_12[4];
};


struct get_window_tree_request
{
    struct request_header __header;
    user_handle_t handle;
};


struct get_window_tree_reply
{
    struct reply_header __header;
    user_handle_t parent;
    user_handle_t owner;
    user_handle_t next_sibling;
    user_handle_t prev_sibling;
    user_handle_t first_sibling;
    user_handle_t last_sibling;
    user_handle_t first_child;
    user_handle_t last_child;
};


struct set_window_pos_request
{
    struct request_header __header;
    unsigned short swp_flags;
    unsigned short paint_flags;
    user_handle_t handle;
    user_handle_t previous;
    rectangle_t window;
    rectangle_t client;
};


struct set_window_pos_reply
{
    struct reply_header __header;
    unsigned int new_style;
    unsigned int new_ex_style;
    user_handle_t surface_win;
    int needs_update;
};


struct get_window_rectangles_request
{
    struct request_header __header;
    user_handle_t handle;
    int relative;
    int dpi;
};


struct get_window_rectangles_reply
{
    struct reply_header __header;
    rectangle_t window;
    rectangle_t client;
};


enum coords_relative
{
    coords_relative_DUMMY = 0
};


struct get_window_text_request
{
    struct request_header __header;
    user_handle_t handle;
};


struct get_window_text_reply
{
    struct reply_header __header;
    data_size_t length;
    char __pad_12[4];
};


struct set_window_text_request
{
    struct request_header __header;
    user_handle_t handle;
};


struct set_window_text_reply
{
    struct reply_header __header;
};


struct get_windows_offset_request
{
    struct request_header __header;
    user_handle_t from;
    user_handle_t to;
    int dpi;
};


struct get_windows_offset_reply
{
    struct reply_header __header;
    int x;
    int y;
    int mirror;
    char __pad_20[4];
};


struct get_visible_region_request
{
    struct request_header __header;
    user_handle_t window;
    unsigned int flags;
    char __pad_20[4];
};


struct get_visible_region_reply
{
    struct reply_header __header;
    user_handle_t top_win;
    rectangle_t top_rect;
    rectangle_t win_rect;
    unsigned int paint_flags;
    data_size_t total_size;
    char __pad_52[4];
};


struct get_surface_region_request
{
    struct request_header __header;
    user_handle_t window;
};


struct get_surface_region_reply
{
    struct reply_header __header;
    rectangle_t visible_rect;
    data_size_t total_size;
    char __pad_28[4];
};


struct get_window_region_request
{
    struct request_header __header;
    user_handle_t window;
};


struct get_window_region_reply
{
    struct reply_header __header;
    data_size_t total_size;
    char __pad_12[4];
};


struct set_window_region_request
{
    struct request_header __header;
    user_handle_t window;
    int redraw;
    char __pad_20[4];
};


struct set_window_region_reply
{
    struct reply_header __header;
};


struct get_update_region_request
{
    struct request_header __header;
    user_handle_t window;
    user_handle_t from_child;
    unsigned int flags;
};


struct get_update_region_reply
{
    struct reply_header __header;
    user_handle_t child;
    unsigned int flags;
    data_size_t total_size;
    char __pad_20[4];
};


struct update_window_zorder_request
{
    struct request_header __header;
    user_handle_t window;
    rectangle_t rect;
};


struct update_window_zorder_reply
{
    struct reply_header __header;
};


struct redraw_window_request
{
    struct request_header __header;
    user_handle_t window;
    unsigned int flags;
    char __pad_20[4];
};


struct redraw_window_reply
{
    struct reply_header __header;
};


struct set_window_property_request
{
    struct request_header __header;
    user_handle_t window;
    lparam_t data;
    atom_t atom;
    char __pad_28[4];
};


struct set_window_property_reply
{
    struct reply_header __header;
};


struct remove_window_property_request
{
    struct request_header __header;
    user_handle_t window;
    atom_t atom;
    char __pad_20[4];
};


struct remove_window_property_reply
{
    struct reply_header __header;
    lparam_t data;
};


struct get_window_property_request
{
    struct request_header __header;
    user_handle_t window;
    atom_t atom;
    char __pad_20[4];
};


struct get_window_property_reply
{
    struct reply_header __header;
    lparam_t data;
};


struct get_window_properties_request
{
    struct request_header __header;
    user_handle_t window;
};


struct get_window_properties_reply
{
    struct reply_header __header;
    int total;
    char __pad_12[4];
};


struct create_winstation_request
{
    struct request_header __header;
    unsigned int flags;
    unsigned int access;
    unsigned int attributes;
    obj_handle_t rootdir;
    char __pad_28[4];
};


struct create_winstation_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    char __pad_12[4];
};


struct open_winstation_request
{
    struct request_header __header;
    unsigned int access;
    unsigned int attributes;
    obj_handle_t rootdir;
};


struct open_winstation_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    char __pad_12[4];
};


struct close_winstation_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct close_winstation_reply
{
    struct reply_header __header;
};


struct get_process_winstation_request
{
    struct request_header __header;
    char __pad_12[4];
};


struct get_process_winstation_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    char __pad_12[4];
};


struct set_process_winstation_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct set_process_winstation_reply
{
    struct reply_header __header;
};


struct enum_winstation_request
{
    struct request_header __header;
    unsigned int index;
};


struct enum_winstation_reply
{
    struct reply_header __header;
    unsigned int next;
    char __pad_12[4];
};


struct create_desktop_request
{
    struct request_header __header;
    unsigned int flags;
    unsigned int access;
    unsigned int attributes;
};


struct create_desktop_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    char __pad_12[4];
};


struct open_desktop_request
{
    struct request_header __header;
    obj_handle_t winsta;
    unsigned int flags;
    unsigned int access;
    unsigned int attributes;
    char __pad_28[4];
};


struct open_desktop_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    char __pad_12[4];
};


struct open_input_desktop_request
{
    struct request_header __header;
    unsigned int flags;
    unsigned int access;
    unsigned int attributes;
};


struct open_input_desktop_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    char __pad_12[4];
};


struct close_desktop_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct close_desktop_reply
{
    struct reply_header __header;
};


struct get_thread_desktop_request
{
    struct request_header __header;
    thread_id_t tid;
};


struct get_thread_desktop_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    char __pad_12[4];
};


struct set_thread_desktop_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct set_thread_desktop_reply
{
    struct reply_header __header;
};


struct enum_desktop_request
{
    struct request_header __header;
    obj_handle_t winstation;
    unsigned int index;
    char __pad_20[4];
};


struct enum_desktop_reply
{
    struct reply_header __header;
    unsigned int next;
    char __pad_12[4];
};


struct set_user_object_info_request
{
    struct request_header __header;
    obj_handle_t handle;
    unsigned int flags;
    unsigned int obj_flags;
};


struct set_user_object_info_reply
{
    struct reply_header __header;
    int is_desktop;
    unsigned int old_obj_flags;
};


struct register_hotkey_request
{
    struct request_header __header;
    user_handle_t window;
    int id;
    unsigned int flags;
    unsigned int vkey;
    char __pad_28[4];
};


struct register_hotkey_reply
{
    struct reply_header __header;
    int replaced;
    unsigned int flags;
    unsigned int vkey;
    char __pad_20[4];
};


struct unregister_hotkey_request
{
    struct request_header __header;
    user_handle_t window;
    int id;
    char __pad_20[4];
};


struct unregister_hotkey_reply
{
    struct reply_header __header;
    unsigned int flags;
    unsigned int vkey;
};


struct attach_thread_input_request
{
    struct request_header __header;
    thread_id_t tid_from;
    thread_id_t tid_to;
    int attach;
};


struct attach_thread_input_reply
{
    struct reply_header __header;
};


struct get_thread_input_request
{
    struct request_header __header;
    thread_id_t tid;
};


struct get_thread_input_reply
{
    struct reply_header __header;
    user_handle_t focus;
    user_handle_t capture;
    user_handle_t active;
    user_handle_t foreground;
    user_handle_t menu_owner;
    user_handle_t move_size;
    user_handle_t caret;
    user_handle_t cursor;
    int show_count;
    rectangle_t rect;
    char __pad_60[4];
};


struct get_last_input_time_request
{
    struct request_header __header;
    char __pad_12[4];
};


struct get_last_input_time_reply
{
    struct reply_header __header;
    unsigned int time;
    char __pad_12[4];
};


struct get_key_state_request
{
    struct request_header __header;
    thread_id_t tid;
    int key;
    char __pad_20[4];
};


struct get_key_state_reply
{
    struct reply_header __header;
    unsigned char state;
    char __pad_9[7];
};


struct set_key_state_request
{
    struct request_header __header;
    thread_id_t tid;
    int async;
    char __pad_20[4];
};


struct set_key_state_reply
{
    struct reply_header __header;
};


struct set_foreground_window_request
{
    struct request_header __header;
    user_handle_t handle;
};


struct set_foreground_window_reply
{
    struct reply_header __header;
    user_handle_t previous;
    int send_msg_old;
    int send_msg_new;
    char __pad_20[4];
};


struct set_focus_window_request
{
    struct request_header __header;
    user_handle_t handle;
};


struct set_focus_window_reply
{
    struct reply_header __header;
    user_handle_t previous;
    char __pad_12[4];
};


struct set_active_window_request
{
    struct request_header __header;
    user_handle_t handle;
};


struct set_active_window_reply
{
    struct reply_header __header;
    user_handle_t previous;
    char __pad_12[4];
};


struct set_capture_window_request
{
    struct request_header __header;
    user_handle_t handle;
    unsigned int flags;
    char __pad_20[4];
};


struct set_capture_window_reply
{
    struct reply_header __header;
    user_handle_t previous;
    user_handle_t full_handle;
};


struct set_caret_window_request
{
    struct request_header __header;
    user_handle_t handle;
    int width;
    int height;
};


struct set_caret_window_reply
{
    struct reply_header __header;
    user_handle_t previous;
    rectangle_t old_rect;
    int old_hide;
    int old_state;
    char __pad_36[4];
};


struct set_caret_info_request
{
    struct request_header __header;
    unsigned int flags;
    user_handle_t handle;
    int x;
    int y;
    int hide;
    int state;
    char __pad_36[4];
};


struct set_caret_info_reply
{
    struct reply_header __header;
    user_handle_t full_handle;
    rectangle_t old_rect;
    int old_hide;
    int old_state;
    char __pad_36[4];
};


enum caret_state
{
    caret_state_DUMMY = 0
};


struct set_hook_request
{
    struct request_header __header;
    int id;
    process_id_t pid;
    thread_id_t tid;
    int event_min;
    int event_max;
    client_ptr_t proc;
    int flags;
    int unicode;
};


struct set_hook_reply
{
    struct reply_header __header;
    user_handle_t handle;
    unsigned int active_hooks;
};


struct remove_hook_request
{
    struct request_header __header;
    user_handle_t handle;
    client_ptr_t proc;
    int id;
    char __pad_28[4];
};


struct remove_hook_reply
{
    struct reply_header __header;
    unsigned int active_hooks;
    char __pad_12[4];
};


struct start_hook_chain_request
{
    struct request_header __header;
    int id;
    int event;
    user_handle_t window;
    int object_id;
    int child_id;
};


struct start_hook_chain_reply
{
    struct reply_header __header;
    user_handle_t handle;
    process_id_t pid;
    thread_id_t tid;
    int unicode;
    client_ptr_t proc;
    unsigned int active_hooks;
    char __pad_36[4];
};


struct finish_hook_chain_request
{
    struct request_header __header;
    int id;
};


struct finish_hook_chain_reply
{
    struct reply_header __header;
};


struct get_hook_info_request
{
    struct request_header __header;
    user_handle_t handle;
    int get_next;
    int event;
    user_handle_t window;
    int object_id;
    int child_id;
    char __pad_36[4];
};


struct get_hook_info_reply
{
    struct reply_header __header;
    user_handle_t handle;
    int id;
    process_id_t pid;
    thread_id_t tid;
    client_ptr_t proc;
    int unicode;
    char __pad_36[4];
};


struct create_class_request
{
    struct request_header __header;
    int local;
    atom_t atom;
    unsigned int style;
    mod_handle_t instance;
    int extra;
    int win_extra;
    client_ptr_t client_ptr;
    data_size_t name_offset;
    char __pad_52[4];
};


struct create_class_reply
{
    struct reply_header __header;
    atom_t atom;
    char __pad_12[4];
};


struct destroy_class_request
{
    struct request_header __header;
    atom_t atom;
    mod_handle_t instance;
};


struct destroy_class_reply
{
    struct reply_header __header;
    client_ptr_t client_ptr;
};


struct set_class_info_request
{
    struct request_header __header;
    user_handle_t window;
    unsigned int flags;
    atom_t atom;
    unsigned int style;
    int win_extra;
    mod_handle_t instance;
    int extra_offset;
    data_size_t extra_size;
    lparam_t extra_value;
};


struct set_class_info_reply
{
    struct reply_header __header;
    atom_t old_atom;
    atom_t base_atom;
    mod_handle_t old_instance;
    lparam_t old_extra_value;
    unsigned int old_style;
    int old_extra;
    int old_win_extra;
    char __pad_44[4];
};


struct open_clipboard_request
{
    struct request_header __header;
    user_handle_t window;
};


struct open_clipboard_reply
{
    struct reply_header __header;
    user_handle_t owner;
    char __pad_12[4];
};


struct close_clipboard_request
{
    struct request_header __header;
    char __pad_12[4];
};


struct close_clipboard_reply
{
    struct reply_header __header;
    user_handle_t viewer;
    user_handle_t owner;
};


struct empty_clipboard_request
{
    struct request_header __header;
    char __pad_12[4];
};


struct empty_clipboard_reply
{
    struct reply_header __header;
};


struct set_clipboard_data_request
{
    struct request_header __header;
    unsigned int format;
    unsigned int lcid;
    char __pad_20[4];
};


struct set_clipboard_data_reply
{
    struct reply_header __header;
    unsigned int seqno;
    char __pad_12[4];
};


struct get_clipboard_data_request
{
    struct request_header __header;
    unsigned int format;
    int render;
    int cached;
    unsigned int seqno;
    char __pad_28[4];
};


struct get_clipboard_data_reply
{
    struct reply_header __header;
    unsigned int from;
    user_handle_t owner;
    unsigned int seqno;
    data_size_t total;
};


struct get_clipboard_formats_request
{
    struct request_header __header;
    unsigned int format;
};


struct get_clipboard_formats_reply
{
    struct reply_header __header;
    unsigned int count;
    char __pad_12[4];
};


struct enum_clipboard_formats_request
{
    struct request_header __header;
    unsigned int previous;
};


struct enum_clipboard_formats_reply
{
    struct reply_header __header;
    unsigned int format;
    char __pad_12[4];
};


struct release_clipboard_request
{
    struct request_header __header;
    user_handle_t owner;
};


struct release_clipboard_reply
{
    struct reply_header __header;
    user_handle_t viewer;
    user_handle_t owner;
};


struct get_clipboard_info_request
{
    struct request_header __header;
    char __pad_12[4];
};


struct get_clipboard_info_reply
{
    struct reply_header __header;
    user_handle_t window;
    user_handle_t owner;
    user_handle_t viewer;
    unsigned int seqno;
};


struct set_clipboard_viewer_request
{
    struct request_header __header;
    user_handle_t viewer;
    user_handle_t previous;
    char __pad_20[4];
};


struct set_clipboard_viewer_reply
{
    struct reply_header __header;
    user_handle_t old_viewer;
    user_handle_t owner;
};


struct add_clipboard_listener_request
{
    struct request_header __header;
    user_handle_t window;
};


struct add_clipboard_listener_reply
{
    struct reply_header __header;
};


struct remove_clipboard_listener_request
{
    struct request_header __header;
    user_handle_t window;
};


struct remove_clipboard_listener_reply
{
    struct reply_header __header;
};


struct open_token_request
{
    struct request_header __header;
    obj_handle_t handle;
    unsigned int access;
    unsigned int attributes;
    unsigned int flags;
    char __pad_28[4];
};


struct open_token_reply
{
    struct reply_header __header;
    obj_handle_t token;
    char __pad_12[4];
};


struct set_global_windows_request
{
    struct request_header __header;
    unsigned int flags;
    user_handle_t shell_window;
    user_handle_t shell_listview;
    user_handle_t progman_window;
    user_handle_t taskman_window;
};


struct set_global_windows_reply
{
    struct reply_header __header;
    user_handle_t old_shell_window;
    user_handle_t old_shell_listview;
    user_handle_t old_progman_window;
    user_handle_t old_taskman_window;
};


struct adjust_token_privileges_request
{
    struct request_header __header;
    obj_handle_t handle;
    int disable_all;
    int get_modified_state;
};


struct adjust_token_privileges_reply
{
    struct reply_header __header;
    unsigned int len;
    char __pad_12[4];
};


struct get_token_privileges_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct get_token_privileges_reply
{
    struct reply_header __header;
    unsigned int len;
    char __pad_12[4];
};


struct check_token_privileges_request
{
    struct request_header __header;
    obj_handle_t handle;
    int all_required;
    char __pad_20[4];
};


struct check_token_privileges_reply
{
    struct reply_header __header;
    int has_privileges;
    char __pad_12[4];
};


struct duplicate_token_request
{
    struct request_header __header;
    obj_handle_t handle;
    unsigned int access;
    int primary;
    int impersonation_level;
    char __pad_28[4];
};


struct duplicate_token_reply
{
    struct reply_header __header;
    obj_handle_t new_handle;
    char __pad_12[4];
};


struct access_check_request
{
    struct request_header __header;
    obj_handle_t handle;
    unsigned int desired_access;
    unsigned int mapping_read;
    unsigned int mapping_write;
    unsigned int mapping_execute;
    unsigned int mapping_all;
    char __pad_36[4];
};


struct access_check_reply
{
    struct reply_header __header;
    unsigned int access_granted;
    unsigned int access_status;
    unsigned int privileges_len;
    char __pad_20[4];
};


struct get_token_sid_request
{
    struct request_header __header;
    obj_handle_t handle;
    unsigned int which_sid;
    char __pad_20[4];
};


struct get_token_sid_reply
{
    struct reply_header __header;
    data_size_t sid_len;
    char __pad_12[4];
};


struct get_token_groups_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct get_token_groups_reply
{
    struct reply_header __header;
    data_size_t user_len;
    char __pad_12[4];
};


struct get_token_default_dacl_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct get_token_default_dacl_reply
{
    struct reply_header __header;
    data_size_t acl_len;
    char __pad_12[4];
};


struct set_token_default_dacl_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct set_token_default_dacl_reply
{
    struct reply_header __header;
};


struct set_security_object_request
{
    struct request_header __header;
    obj_handle_t handle;
    unsigned int security_info;
    char __pad_20[4];
};


struct set_security_object_reply
{
    struct reply_header __header;
};


struct get_security_object_request
{
    struct request_header __header;
    obj_handle_t handle;
    unsigned int security_info;
    char __pad_20[4];
};


struct get_security_object_reply
{
    struct reply_header __header;
    unsigned int sd_len;
    char __pad_12[4];
};


struct handle_info
{
    process_id_t owner;
    obj_handle_t handle;
    unsigned int access;
};


struct get_system_handles_request
{
    struct request_header __header;
    char __pad_12[4];
};


struct get_system_handles_reply
{
    struct reply_header __header;
    unsigned int count;
    char __pad_12[4];
};


struct create_mailslot_request
{
    struct request_header __header;
    unsigned int access;
    timeout_t read_timeout;
    unsigned int max_msgsize;
    char __pad_28[4];
};


struct create_mailslot_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    char __pad_12[4];
};


struct set_mailslot_info_request
{
    struct request_header __header;
    obj_handle_t handle;
    timeout_t read_timeout;
    unsigned int flags;
    char __pad_28[4];
};


struct set_mailslot_info_reply
{
    struct reply_header __header;
    timeout_t read_timeout;
    unsigned int max_msgsize;
    char __pad_20[4];
};


struct create_directory_request
{
    struct request_header __header;
    unsigned int access;
};


struct create_directory_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    char __pad_12[4];
};


struct open_directory_request
{
    struct request_header __header;
    unsigned int access;
    unsigned int attributes;
    obj_handle_t rootdir;
};


struct open_directory_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    char __pad_12[4];
};


struct get_directory_entry_request
{
    struct request_header __header;
    obj_handle_t handle;
    unsigned int index;
    char __pad_20[4];
};


struct get_directory_entry_reply
{
    struct reply_header __header;
    data_size_t name_len;
    char __pad_12[4];
};


struct create_symlink_request
{
    struct request_header __header;
    unsigned int access;
};


struct create_symlink_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    char __pad_12[4];
};


struct open_symlink_request
{
    struct request_header __header;
    unsigned int access;
    unsigned int attributes;
    obj_handle_t rootdir;
};


struct open_symlink_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    char __pad_12[4];
};


struct query_symlink_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct query_symlink_reply
{
    struct reply_header __header;
    data_size_t total;
    char __pad_12[4];
};


struct get_object_info_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct get_object_info_reply
{
    struct reply_header __header;
    unsigned int access;
    unsigned int ref_count;
    unsigned int handle_count;
    data_size_t total;
};


struct get_object_type_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct get_object_type_reply
{
    struct reply_header __header;
    data_size_t total;
    char __pad_12[4];
};


struct unlink_object_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct unlink_object_reply
{
    struct reply_header __header;
};


struct get_token_impersonation_level_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct get_token_impersonation_level_reply
{
    struct reply_header __header;
    int impersonation_level;
    char __pad_12[4];
};


struct allocate_locally_unique_id_request
{
    struct request_header __header;
    char __pad_12[4];
};


struct allocate_locally_unique_id_reply
{
    struct reply_header __header;
    luid_t luid;
};


struct create_device_manager_request
{
    struct request_header __header;
    unsigned int access;
    unsigned int attributes;
    char __pad_20[4];
};


struct create_device_manager_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    char __pad_12[4];
};


struct create_device_request
{
    struct request_header __header;
    obj_handle_t rootdir;
    client_ptr_t user_ptr;
    obj_handle_t manager;
    char __pad_28[4];
};


struct create_device_reply
{
    struct reply_header __header;
};


struct delete_device_request
{
    struct request_header __header;
    obj_handle_t manager;
    client_ptr_t device;
};


struct delete_device_reply
{
    struct reply_header __header;
};


struct get_next_device_request_request
{
    struct request_header __header;
    obj_handle_t manager;
    obj_handle_t prev;
    unsigned int status;
    client_ptr_t user_ptr;
};


struct get_next_device_request_reply
{
    struct reply_header __header;
    irp_params_t params;
    obj_handle_t next;
    thread_id_t client_tid;
    client_ptr_t client_thread;
    data_size_t in_size;
    char __pad_60[4];
};


struct get_kernel_object_ptr_request
{
    struct request_header __header;
    obj_handle_t manager;
    obj_handle_t handle;
    char __pad_20[4];
};


struct get_kernel_object_ptr_reply
{
    struct reply_header __header;
    client_ptr_t user_ptr;
};


struct set_kernel_object_ptr_request
{
    struct request_header __header;
    obj_handle_t manager;
    obj_handle_t handle;
    char __pad_20[4];
    client_ptr_t user_ptr;
};


struct set_kernel_object_ptr_reply
{
    struct reply_header __header;
};


struct grab_kernel_object_request
{
    struct request_header __header;
    obj_handle_t manager;
    client_ptr_t user_ptr;
};


struct grab_kernel_object_reply
{
    struct reply_header __header;
};


struct release_kernel_object_request
{
    struct request_header __header;
    obj_handle_t manager;
    client_ptr_t user_ptr;
};


struct release_kernel_object_reply
{
    struct reply_header __header;
};


struct get_kernel_object_handle_request
{
    struct request_header __header;
    obj_handle_t manager;
    client_ptr_t user_ptr;
    unsigned int access;
    char __pad_28[4];
};


struct get_kernel_object_handle_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    char __pad_12[4];
};


struct make_process_system_request
{
    struct request_header __header;
    char __pad_12[4];
};


struct make_process_system_reply
{
    struct reply_header __header;
    obj_handle_t event;
    char __pad_12[4];
};


struct get_token_statistics_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct get_token_statistics_reply
{
    struct reply_header __header;
    luid_t token_id;
    luid_t modified_id;
    int primary;
    int impersonation_level;
    int group_count;
    int privilege_count;
};


struct create_completion_request
{
    struct request_header __header;
    unsigned int access;
    unsigned int concurrent;
    char __pad_20[4];
};


struct create_completion_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    char __pad_12[4];
};


struct open_completion_request
{
    struct request_header __header;
    unsigned int access;
    unsigned int attributes;
    obj_handle_t rootdir;
};


struct open_completion_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    char __pad_12[4];
};


struct add_completion_request
{
    struct request_header __header;
    obj_handle_t handle;
    apc_param_t ckey;
    apc_param_t cvalue;
    apc_param_t information;
    unsigned int status;
    char __pad_44[4];
};


struct add_completion_reply
{
    struct reply_header __header;
};


struct remove_completion_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct remove_completion_reply
{
    struct reply_header __header;
    apc_param_t ckey;
    apc_param_t cvalue;
    apc_param_t information;
    unsigned int status;
    char __pad_36[4];
};


struct query_completion_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct query_completion_reply
{
    struct reply_header __header;
    unsigned int depth;
    char __pad_12[4];
};


struct set_completion_info_request
{
    struct request_header __header;
    obj_handle_t handle;
    apc_param_t ckey;
    obj_handle_t chandle;
    char __pad_28[4];
};


struct set_completion_info_reply
{
    struct reply_header __header;
};


struct add_fd_completion_request
{
    struct request_header __header;
    obj_handle_t handle;
    apc_param_t cvalue;
    apc_param_t information;
    unsigned int status;
    int async;
};


struct add_fd_completion_reply
{
    struct reply_header __header;
};


struct set_fd_completion_mode_request
{
    struct request_header __header;
    obj_handle_t handle;
    unsigned int flags;
    char __pad_20[4];
};


struct set_fd_completion_mode_reply
{
    struct reply_header __header;
};


struct set_fd_disp_info_request
{
    struct request_header __header;
    obj_handle_t handle;
    int unlink;
    char __pad_20[4];
};


struct set_fd_disp_info_reply
{
    struct reply_header __header;
};


struct set_fd_name_info_request
{
    struct request_header __header;
    obj_handle_t handle;
    obj_handle_t rootdir;
    int link;
};


struct set_fd_name_info_reply
{
    struct reply_header __header;
};


struct get_window_layered_info_request
{
    struct request_header __header;
    user_handle_t handle;
};


struct get_window_layered_info_reply
{
    struct reply_header __header;
    unsigned int color_key;
    unsigned int alpha;
    unsigned int flags;
    char __pad_20[4];
};


struct set_window_layered_info_request
{
    struct request_header __header;
    user_handle_t handle;
    unsigned int color_key;
    unsigned int alpha;
    unsigned int flags;
    char __pad_28[4];
};


struct set_window_layered_info_reply
{
    struct reply_header __header;
};


struct alloc_user_handle_request
{
    struct request_header __header;
    char __pad_12[4];
};


struct alloc_user_handle_reply
{
    struct reply_header __header;
    user_handle_t handle;
    char __pad_12[4];
};


struct free_user_handle_request
{
    struct request_header __header;
    user_handle_t handle;
};


struct free_user_handle_reply
{
    struct reply_header __header;
};


struct set_cursor_request
{
    struct request_header __header;
    unsigned int flags;
    user_handle_t handle;
    int show_count;
    int x;
    int y;
    rectangle_t clip;
    unsigned int clip_msg;
    char __pad_52[4];
};


struct set_cursor_reply
{
    struct reply_header __header;
    user_handle_t prev_handle;
    int prev_count;
    int prev_x;
    int prev_y;
    int new_x;
    int new_y;
    rectangle_t new_clip;
    unsigned int last_change;
    char __pad_52[4];
};


struct update_rawinput_devices_request
{
    struct request_header __header;
    char __pad_12[4];
};


struct update_rawinput_devices_reply
{
    struct reply_header __header;
};


struct get_suspend_context_request
{
    struct request_header __header;
    char __pad_12[4];
};


struct get_suspend_context_reply
{
    struct reply_header __header;
};


struct set_suspend_context_request
{
    struct request_header __header;
    char __pad_12[4];
};


struct set_suspend_context_reply
{
    struct reply_header __header;
};


struct create_job_request
{
    struct request_header __header;
    unsigned int access;
};


struct create_job_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    char __pad_12[4];
};


struct open_job_request
{
    struct request_header __header;
    unsigned int access;
    unsigned int attributes;
    obj_handle_t rootdir;
};


struct open_job_reply
{
    struct reply_header __header;
    obj_handle_t handle;
    char __pad_12[4];
};


struct assign_job_request
{
    struct request_header __header;
    obj_handle_t job;
    obj_handle_t process;
    char __pad_20[4];
};


struct assign_job_reply
{
    struct reply_header __header;
};


struct process_in_job_request
{
    struct request_header __header;
    obj_handle_t job;
    obj_handle_t process;
    char __pad_20[4];
};


struct process_in_job_reply
{
    struct reply_header __header;
};


struct set_job_limits_request
{
    struct request_header __header;
    obj_handle_t handle;
    unsigned int limit_flags;
    char __pad_20[4];
};


struct set_job_limits_reply
{
    struct reply_header __header;
};


struct set_job_completion_port_request
{
    struct request_header __header;
    obj_handle_t job;
    obj_handle_t port;
    char __pad_20[4];
    client_ptr_t key;
};


struct set_job_completion_port_reply
{
    struct reply_header __header;
};


struct terminate_job_request
{
    struct request_header __header;
    obj_handle_t handle;
    int status;
    char __pad_20[4];
};


struct terminate_job_reply
{
    struct reply_header __header;
};


struct suspend_process_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct suspend_process_reply
{
    struct reply_header __header;
};


struct resume_process_request
{
    struct request_header __header;
    obj_handle_t handle;
};


struct resume_process_reply
{
    struct reply_header __header;
};


enum request
{
    request_DUMMY = 0
};


union generic_request
{
    struct request_max_size max_size;
    struct request_header request_header;
    struct new_process_request new_process_request;
    struct exec_process_request exec_process_request;
    struct get_new_process_info_request get_new_process_info_request;
    struct new_thread_request new_thread_request;
    struct get_startup_info_request get_startup_info_request;
    struct init_process_done_request init_process_done_request;
    struct init_thread_request init_thread_request;
    struct terminate_process_request terminate_process_request;
    struct terminate_thread_request terminate_thread_request;
    struct get_process_info_request get_process_info_request;
    struct get_process_vm_counters_request get_process_vm_counters_request;
    struct set_process_info_request set_process_info_request;
    struct get_thread_info_request get_thread_info_request;
    struct get_thread_times_request get_thread_times_request;
    struct set_thread_info_request set_thread_info_request;
    struct get_dll_info_request get_dll_info_request;
    struct suspend_thread_request suspend_thread_request;
    struct resume_thread_request resume_thread_request;
    struct load_dll_request load_dll_request;
    struct unload_dll_request unload_dll_request;
    struct queue_apc_request queue_apc_request;
    struct get_apc_result_request get_apc_result_request;
    struct close_handle_request close_handle_request;
    struct set_handle_info_request set_handle_info_request;
    struct dup_handle_request dup_handle_request;
    struct open_process_request open_process_request;
    struct open_thread_request open_thread_request;
    struct select_request select_request;
    struct create_event_request create_event_request;
    struct event_op_request event_op_request;
    struct query_event_request query_event_request;
    struct open_event_request open_event_request;
    struct create_keyed_event_request create_keyed_event_request;
    struct open_keyed_event_request open_keyed_event_request;
    struct create_mutex_request create_mutex_request;
    struct release_mutex_request release_mutex_request;
    struct open_mutex_request open_mutex_request;
    struct query_mutex_request query_mutex_request;
    struct create_semaphore_request create_semaphore_request;
    struct release_semaphore_request release_semaphore_request;
    struct query_semaphore_request query_semaphore_request;
    struct open_semaphore_request open_semaphore_request;
    struct create_file_request create_file_request;
    struct open_file_object_request open_file_object_request;
    struct alloc_file_handle_request alloc_file_handle_request;
    struct get_handle_unix_name_request get_handle_unix_name_request;
    struct get_handle_fd_request get_handle_fd_request;
    struct get_directory_cache_entry_request get_directory_cache_entry_request;
    struct flush_request flush_request;
    struct get_file_info_request get_file_info_request;
    struct get_volume_info_request get_volume_info_request;
    struct lock_file_request lock_file_request;
    struct unlock_file_request unlock_file_request;
    struct create_socket_request create_socket_request;
    struct accept_socket_request accept_socket_request;
    struct accept_into_socket_request accept_into_socket_request;
    struct set_socket_event_request set_socket_event_request;
    struct get_socket_event_request get_socket_event_request;
    struct get_socket_info_request get_socket_info_request;
    struct enable_socket_event_request enable_socket_event_request;
    struct set_socket_deferred_request set_socket_deferred_request;
    struct alloc_console_request alloc_console_request;
    struct free_console_request free_console_request;
    struct get_console_renderer_events_request get_console_renderer_events_request;
    struct open_console_request open_console_request;
    struct attach_console_request attach_console_request;
    struct get_console_wait_event_request get_console_wait_event_request;
    struct get_console_mode_request get_console_mode_request;
    struct set_console_mode_request set_console_mode_request;
    struct set_console_input_info_request set_console_input_info_request;
    struct get_console_input_info_request get_console_input_info_request;
    struct append_console_input_history_request append_console_input_history_request;
    struct get_console_input_history_request get_console_input_history_request;
    struct create_console_output_request create_console_output_request;
    struct set_console_output_info_request set_console_output_info_request;
    struct get_console_output_info_request get_console_output_info_request;
    struct write_console_input_request write_console_input_request;
    struct read_console_input_request read_console_input_request;
    struct write_console_output_request write_console_output_request;
    struct fill_console_output_request fill_console_output_request;
    struct read_console_output_request read_console_output_request;
    struct move_console_output_request move_console_output_request;
    struct send_console_signal_request send_console_signal_request;
    struct read_directory_changes_request read_directory_changes_request;
    struct read_change_request read_change_request;
    struct create_mapping_request create_mapping_request;
    struct open_mapping_request open_mapping_request;
    struct get_mapping_info_request get_mapping_info_request;
    struct map_view_request map_view_request;
    struct unmap_view_request unmap_view_request;
    struct get_mapping_committed_range_request get_mapping_committed_range_request;
    struct add_mapping_committed_range_request add_mapping_committed_range_request;
    struct is_same_mapping_request is_same_mapping_request;
    struct create_snapshot_request create_snapshot_request;
    struct next_process_request next_process_request;
    struct next_thread_request next_thread_request;
    struct wait_debug_event_request wait_debug_event_request;
    struct queue_exception_event_request queue_exception_event_request;
    struct get_exception_status_request get_exception_status_request;
    struct continue_debug_event_request continue_debug_event_request;
    struct debug_process_request debug_process_request;
    struct set_debugger_kill_on_exit_request set_debugger_kill_on_exit_request;
    struct read_process_memory_request read_process_memory_request;
    struct write_process_memory_request write_process_memory_request;
    struct create_key_request create_key_request;
    struct open_key_request open_key_request;
    struct delete_key_request delete_key_request;
    struct flush_key_request flush_key_request;
    struct enum_key_request enum_key_request;
    struct set_key_value_request set_key_value_request;
    struct get_key_value_request get_key_value_request;
    struct enum_key_value_request enum_key_value_request;
    struct delete_key_value_request delete_key_value_request;
    struct load_registry_request load_registry_request;
    struct unload_registry_request unload_registry_request;
    struct save_registry_request save_registry_request;
    struct set_registry_notification_request set_registry_notification_request;
    struct create_timer_request create_timer_request;
    struct open_timer_request open_timer_request;
    struct set_timer_request set_timer_request;
    struct cancel_timer_request cancel_timer_request;
    struct get_timer_info_request get_timer_info_request;
    struct get_thread_context_request get_thread_context_request;
    struct set_thread_context_request set_thread_context_request;
    struct get_selector_entry_request get_selector_entry_request;
    struct add_atom_request add_atom_request;
    struct delete_atom_request delete_atom_request;
    struct find_atom_request find_atom_request;
    struct get_atom_information_request get_atom_information_request;
    struct set_atom_information_request set_atom_information_request;
    struct empty_atom_table_request empty_atom_table_request;
    struct init_atom_table_request init_atom_table_request;
    struct get_msg_queue_request get_msg_queue_request;
    struct set_queue_fd_request set_queue_fd_request;
    struct set_queue_mask_request set_queue_mask_request;
    struct get_queue_status_request get_queue_status_request;
    struct get_process_idle_event_request get_process_idle_event_request;
    struct send_message_request send_message_request;
    struct post_quit_message_request post_quit_message_request;
    struct send_hardware_message_request send_hardware_message_request;
    struct get_message_request get_message_request;
    struct reply_message_request reply_message_request;
    struct accept_hardware_message_request accept_hardware_message_request;
    struct get_message_reply_request get_message_reply_request;
    struct set_win_timer_request set_win_timer_request;
    struct kill_win_timer_request kill_win_timer_request;
    struct is_window_hung_request is_window_hung_request;
    struct get_serial_info_request get_serial_info_request;
    struct set_serial_info_request set_serial_info_request;
    struct register_async_request register_async_request;
    struct cancel_async_request cancel_async_request;
    struct get_async_result_request get_async_result_request;
    struct read_request read_request;
    struct write_request write_request;
    struct ioctl_request ioctl_request;
    struct set_irp_result_request set_irp_result_request;
    struct create_named_pipe_request create_named_pipe_request;
    struct set_named_pipe_info_request set_named_pipe_info_request;
    struct create_window_request create_window_request;
    struct destroy_window_request destroy_window_request;
    struct get_desktop_window_request get_desktop_window_request;
    struct set_window_owner_request set_window_owner_request;
    struct get_window_info_request get_window_info_request;
    struct set_window_info_request set_window_info_request;
    struct set_parent_request set_parent_request;
    struct get_window_parents_request get_window_parents_request;
    struct get_window_children_request get_window_children_request;
    struct get_window_children_from_point_request get_window_children_from_point_request;
    struct get_window_tree_request get_window_tree_request;
    struct set_window_pos_request set_window_pos_request;
    struct get_window_rectangles_request get_window_rectangles_request;
    struct get_window_text_request get_window_text_request;
    struct set_window_text_request set_window_text_request;
    struct get_windows_offset_request get_windows_offset_request;
    struct get_visible_region_request get_visible_region_request;
    struct get_surface_region_request get_surface_region_request;
    struct get_window_region_request get_window_region_request;
    struct set_window_region_request set_window_region_request;
    struct get_update_region_request get_update_region_request;
    struct update_window_zorder_request update_window_zorder_request;
    struct redraw_window_request redraw_window_request;
    struct set_window_property_request set_window_property_request;
    struct remove_window_property_request remove_window_property_request;
    struct get_window_property_request get_window_property_request;
    struct get_window_properties_request get_window_properties_request;
    struct create_winstation_request create_winstation_request;
    struct open_winstation_request open_winstation_request;
    struct close_winstation_request close_winstation_request;
    struct get_process_winstation_request get_process_winstation_request;
    struct set_process_winstation_request set_process_winstation_request;
    struct enum_winstation_request enum_winstation_request;
    struct create_desktop_request create_desktop_request;
    struct open_desktop_request open_desktop_request;
    struct open_input_desktop_request open_input_desktop_request;
    struct close_desktop_request close_desktop_request;
    struct get_thread_desktop_request get_thread_desktop_request;
    struct set_thread_desktop_request set_thread_desktop_request;
    struct enum_desktop_request enum_desktop_request;
    struct set_user_object_info_request set_user_object_info_request;
    struct register_hotkey_request register_hotkey_request;
    struct unregister_hotkey_request unregister_hotkey_request;
    struct attach_thread_input_request attach_thread_input_request;
    struct get_thread_input_request get_thread_input_request;
    struct get_last_input_time_request get_last_input_time_request;
    struct get_key_state_request get_key_state_request;
    struct set_key_state_request set_key_state_request;
    struct set_foreground_window_request set_foreground_window_request;
    struct set_focus_window_request set_focus_window_request;
    struct set_active_window_request set_active_window_request;
    struct set_capture_window_request set_capture_window_request;
    struct set_caret_window_request set_caret_window_request;
    struct set_caret_info_request set_caret_info_request;
    struct set_hook_request set_hook_request;
    struct remove_hook_request remove_hook_request;
    struct start_hook_chain_request start_hook_chain_request;
    struct finish_hook_chain_request finish_hook_chain_request;
    struct get_hook_info_request get_hook_info_request;
    struct create_class_request create_class_request;
    struct destroy_class_request destroy_class_request;
    struct set_class_info_request set_class_info_request;
    struct open_clipboard_request open_clipboard_request;
    struct close_clipboard_request close_clipboard_request;
    struct empty_clipboard_request empty_clipboard_request;
    struct set_clipboard_data_request set_clipboard_data_request;
    struct get_clipboard_data_request get_clipboard_data_request;
    struct get_clipboard_formats_request get_clipboard_formats_request;
    struct enum_clipboard_formats_request enum_clipboard_formats_request;
    struct release_clipboard_request release_clipboard_request;
    struct get_clipboard_info_request get_clipboard_info_request;
    struct set_clipboard_viewer_request set_clipboard_viewer_request;
    struct add_clipboard_listener_request add_clipboard_listener_request;
    struct remove_clipboard_listener_request remove_clipboard_listener_request;
    struct open_token_request open_token_request;
    struct set_global_windows_request set_global_windows_request;
    struct adjust_token_privileges_request adjust_token_privileges_request;
    struct get_token_privileges_request get_token_privileges_request;
    struct check_token_privileges_request check_token_privileges_request;
    struct duplicate_token_request duplicate_token_request;
    struct access_check_request access_check_request;
    struct get_token_sid_request get_token_sid_request;
    struct get_token_groups_request get_token_groups_request;
    struct get_token_default_dacl_request get_token_default_dacl_request;
    struct set_token_default_dacl_request set_token_default_dacl_request;
    struct set_security_object_request set_security_object_request;
    struct get_security_object_request get_security_object_request;
    struct get_system_handles_request get_system_handles_request;
    struct create_mailslot_request create_mailslot_request;
    struct set_mailslot_info_request set_mailslot_info_request;
    struct create_directory_request create_directory_request;
    struct open_directory_request open_directory_request;
    struct get_directory_entry_request get_directory_entry_request;
    struct create_symlink_request create_symlink_request;
    struct open_symlink_request open_symlink_request;
    struct query_symlink_request query_symlink_request;
    struct get_object_info_request get_object_info_request;
    struct get_object_type_request get_object_type_request;
    struct unlink_object_request unlink_object_request;
    struct get_token_impersonation_level_request get_token_impersonation_level_request;
    struct allocate_locally_unique_id_request allocate_locally_unique_id_request;
    struct create_device_manager_request create_device_manager_request;
    struct create_device_request create_device_request;
    struct delete_device_request delete_device_request;
    struct get_next_device_request_request get_next_device_request_request;
    struct get_kernel_object_ptr_request get_kernel_object_ptr_request;
    struct set_kernel_object_ptr_request set_kernel_object_ptr_request;
    struct grab_kernel_object_request grab_kernel_object_request;
    struct release_kernel_object_request release_kernel_object_request;
    struct get_kernel_object_handle_request get_kernel_object_handle_request;
    struct make_process_system_request make_process_system_request;
    struct get_token_statistics_request get_token_statistics_request;
    struct create_completion_request create_completion_request;
    struct open_completion_request open_completion_request;
    struct add_completion_request add_completion_request;
    struct remove_completion_request remove_completion_request;
    struct query_completion_request query_completion_request;
    struct set_completion_info_request set_completion_info_request;
    struct add_fd_completion_request add_fd_completion_request;
    struct set_fd_completion_mode_request set_fd_completion_mode_request;
    struct set_fd_disp_info_request set_fd_disp_info_request;
    struct set_fd_name_info_request set_fd_name_info_request;
    struct get_window_layered_info_request get_window_layered_info_request;
    struct set_window_layered_info_request set_window_layered_info_request;
    struct alloc_user_handle_request alloc_user_handle_request;
    struct free_user_handle_request free_user_handle_request;
    struct set_cursor_request set_cursor_request;
    struct update_rawinput_devices_request update_rawinput_devices_request;
    struct get_suspend_context_request get_suspend_context_request;
    struct set_suspend_context_request set_suspend_context_request;
    struct create_job_request create_job_request;
    struct open_job_request open_job_request;
    struct assign_job_request assign_job_request;
    struct process_in_job_request process_in_job_request;
    struct set_job_limits_request set_job_limits_request;
    struct set_job_completion_port_request set_job_completion_port_request;
    struct terminate_job_request terminate_job_request;
    struct suspend_process_request suspend_process_request;
    struct resume_process_request resume_process_request;
};


union generic_reply
{
    struct request_max_size max_size;
    struct reply_header reply_header;
    struct new_process_reply new_process_reply;
    struct exec_process_reply exec_process_reply;
    struct get_new_process_info_reply get_new_process_info_reply;
    struct new_thread_reply new_thread_reply;
    struct get_startup_info_reply get_startup_info_reply;
    struct init_process_done_reply init_process_done_reply;
    struct init_thread_reply init_thread_reply;
    struct terminate_process_reply terminate_process_reply;
    struct terminate_thread_reply terminate_thread_reply;
    struct get_process_info_reply get_process_info_reply;
    struct get_process_vm_counters_reply get_process_vm_counters_reply;
    struct set_process_info_reply set_process_info_reply;
    struct get_thread_info_reply get_thread_info_reply;
    struct get_thread_times_reply get_thread_times_reply;
    struct set_thread_info_reply set_thread_info_reply;
    struct get_dll_info_reply get_dll_info_reply;
    struct suspend_thread_reply suspend_thread_reply;
    struct resume_thread_reply resume_thread_reply;
    struct load_dll_reply load_dll_reply;
    struct unload_dll_reply unload_dll_reply;
    struct queue_apc_reply queue_apc_reply;
    struct get_apc_result_reply get_apc_result_reply;
    struct close_handle_reply close_handle_reply;
    struct set_handle_info_reply set_handle_info_reply;
    struct dup_handle_reply dup_handle_reply;
    struct open_process_reply open_process_reply;
    struct open_thread_reply open_thread_reply;
    struct select_reply select_reply;
    struct create_event_reply create_event_reply;
    struct event_op_reply event_op_reply;
    struct query_event_reply query_event_reply;
    struct open_event_reply open_event_reply;
    struct create_keyed_event_reply create_keyed_event_reply;
    struct open_keyed_event_reply open_keyed_event_reply;
    struct create_mutex_reply create_mutex_reply;
    struct release_mutex_reply release_mutex_reply;
    struct open_mutex_reply open_mutex_reply;
    struct query_mutex_reply query_mutex_reply;
    struct create_semaphore_reply create_semaphore_reply;
    struct release_semaphore_reply release_semaphore_reply;
    struct query_semaphore_reply query_semaphore_reply;
    struct open_semaphore_reply open_semaphore_reply;
    struct create_file_reply create_file_reply;
    struct open_file_object_reply open_file_object_reply;
    struct alloc_file_handle_reply alloc_file_handle_reply;
    struct get_handle_unix_name_reply get_handle_unix_name_reply;
    struct get_handle_fd_reply get_handle_fd_reply;
    struct get_directory_cache_entry_reply get_directory_cache_entry_reply;
    struct flush_reply flush_reply;
    struct get_file_info_reply get_file_info_reply;
    struct get_volume_info_reply get_volume_info_reply;
    struct lock_file_reply lock_file_reply;
    struct unlock_file_reply unlock_file_reply;
    struct create_socket_reply create_socket_reply;
    struct accept_socket_reply accept_socket_reply;
    struct accept_into_socket_reply accept_into_socket_reply;
    struct set_socket_event_reply set_socket_event_reply;
    struct get_socket_event_reply get_socket_event_reply;
    struct get_socket_info_reply get_socket_info_reply;
    struct enable_socket_event_reply enable_socket_event_reply;
    struct set_socket_deferred_reply set_socket_deferred_reply;
    struct alloc_console_reply alloc_console_reply;
    struct free_console_reply free_console_reply;
    struct get_console_renderer_events_reply get_console_renderer_events_reply;
    struct open_console_reply open_console_reply;
    struct attach_console_reply attach_console_reply;
    struct get_console_wait_event_reply get_console_wait_event_reply;
    struct get_console_mode_reply get_console_mode_reply;
    struct set_console_mode_reply set_console_mode_reply;
    struct set_console_input_info_reply set_console_input_info_reply;
    struct get_console_input_info_reply get_console_input_info_reply;
    struct append_console_input_history_reply append_console_input_history_reply;
    struct get_console_input_history_reply get_console_input_history_reply;
    struct create_console_output_reply create_console_output_reply;
    struct set_console_output_info_reply set_console_output_info_reply;
    struct get_console_output_info_reply get_console_output_info_reply;
    struct write_console_input_reply write_console_input_reply;
    struct read_console_input_reply read_console_input_reply;
    struct write_console_output_reply write_console_output_reply;
    struct fill_console_output_reply fill_console_output_reply;
    struct read_console_output_reply read_console_output_reply;
    struct move_console_output_reply move_console_output_reply;
    struct send_console_signal_reply send_console_signal_reply;
    struct read_directory_changes_reply read_directory_changes_reply;
    struct read_change_reply read_change_reply;
    struct create_mapping_reply create_mapping_reply;
    struct open_mapping_reply open_mapping_reply;
    struct get_mapping_info_reply get_mapping_info_reply;
    struct map_view_reply map_view_reply;
    struct unmap_view_reply unmap_view_reply;
    struct get_mapping_committed_range_reply get_mapping_committed_range_reply;
    struct add_mapping_committed_range_reply add_mapping_committed_range_reply;
    struct is_same_mapping_reply is_same_mapping_reply;
    struct create_snapshot_reply create_snapshot_reply;
    struct next_process_reply next_process_reply;
    struct next_thread_reply next_thread_reply;
    struct wait_debug_event_reply wait_debug_event_reply;
    struct queue_exception_event_reply queue_exception_event_reply;
    struct get_exception_status_reply get_exception_status_reply;
    struct continue_debug_event_reply continue_debug_event_reply;
    struct debug_process_reply debug_process_reply;
    struct set_debugger_kill_on_exit_reply set_debugger_kill_on_exit_reply;
    struct read_process_memory_reply read_process_memory_reply;
    struct write_process_memory_reply write_process_memory_reply;
    struct create_key_reply create_key_reply;
    struct open_key_reply open_key_reply;
    struct delete_key_reply delete_key_reply;
    struct flush_key_reply flush_key_reply;
    struct enum_key_reply enum_key_reply;
    struct set_key_value_reply set_key_value_reply;
    struct get_key_value_reply get_key_value_reply;
    struct enum_key_value_reply enum_key_value_reply;
    struct delete_key_value_reply delete_key_value_reply;
    struct load_registry_reply load_registry_reply;
    struct unload_registry_reply unload_registry_reply;
    struct save_registry_reply save_registry_reply;
    struct set_registry_notification_reply set_registry_notification_reply;
    struct create_timer_reply create_timer_reply;
    struct open_timer_reply open_timer_reply;
    struct set_timer_reply set_timer_reply;
    struct cancel_timer_reply cancel_timer_reply;
    struct get_timer_info_reply get_timer_info_reply;
    struct get_thread_context_reply get_thread_context_reply;
    struct set_thread_context_reply set_thread_context_reply;
    struct get_selector_entry_reply get_selector_entry_reply;
    struct add_atom_reply add_atom_reply;
    struct delete_atom_reply delete_atom_reply;
    struct find_atom_reply find_atom_reply;
    struct get_atom_information_reply get_atom_information_reply;
    struct set_atom_information_reply set_atom_information_reply;
    struct empty_atom_table_reply empty_atom_table_reply;
    struct init_atom_table_reply init_atom_table_reply;
    struct get_msg_queue_reply get_msg_queue_reply;
    struct set_queue_fd_reply set_queue_fd_reply;
    struct set_queue_mask_reply set_queue_mask_reply;
    struct get_queue_status_reply get_queue_status_reply;
    struct get_process_idle_event_reply get_process_idle_event_reply;
    struct send_message_reply send_message_reply;
    struct post_quit_message_reply post_quit_message_reply;
    struct send_hardware_message_reply send_hardware_message_reply;
    struct get_message_reply get_message_reply;
    struct reply_message_reply reply_message_reply;
    struct accept_hardware_message_reply accept_hardware_message_reply;
    struct get_message_reply_reply get_message_reply_reply;
    struct set_win_timer_reply set_win_timer_reply;
    struct kill_win_timer_reply kill_win_timer_reply;
    struct is_window_hung_reply is_window_hung_reply;
    struct get_serial_info_reply get_serial_info_reply;
    struct set_serial_info_reply set_serial_info_reply;
    struct register_async_reply register_async_reply;
    struct cancel_async_reply cancel_async_reply;
    struct get_async_result_reply get_async_result_reply;
    struct read_reply read_reply;
    struct write_reply write_reply;
    struct ioctl_reply ioctl_reply;
    struct set_irp_result_reply set_irp_result_reply;
    struct create_named_pipe_reply create_named_pipe_reply;
    struct set_named_pipe_info_reply set_named_pipe_info_reply;
    struct create_window_reply create_window_reply;
    struct destroy_window_reply destroy_window_reply;
    struct get_desktop_window_reply get_desktop_window_reply;
    struct set_window_owner_reply set_window_owner_reply;
    struct get_window_info_reply get_window_info_reply;
    struct set_window_info_reply set_window_info_reply;
    struct set_parent_reply set_parent_reply;
    struct get_window_parents_reply get_window_parents_reply;
    struct get_window_children_reply get_window_children_reply;
    struct get_window_children_from_point_reply get_window_children_from_point_reply;
    struct get_window_tree_reply get_window_tree_reply;
    struct set_window_pos_reply set_window_pos_reply;
    struct get_window_rectangles_reply get_window_rectangles_reply;
    struct get_window_text_reply get_window_text_reply;
    struct set_window_text_reply set_window_text_reply;
    struct get_windows_offset_reply get_windows_offset_reply;
    struct get_visible_region_reply get_visible_region_reply;
    struct get_surface_region_reply get_surface_region_reply;
    struct get_window_region_reply get_window_region_reply;
    struct set_window_region_reply set_window_region_reply;
    struct get_update_region_reply get_update_region_reply;
    struct update_window_zorder_reply update_window_zorder_reply;
    struct redraw_window_reply redraw_window_reply;
    struct set_window_property_reply set_window_property_reply;
    struct remove_window_property_reply remove_window_property_reply;
    struct get_window_property_reply get_window_property_reply;
    struct get_window_properties_reply get_window_properties_reply;
    struct create_winstation_reply create_winstation_reply;
    struct open_winstation_reply open_winstation_reply;
    struct close_winstation_reply close_winstation_reply;
    struct get_process_winstation_reply get_process_winstation_reply;
    struct set_process_winstation_reply set_process_winstation_reply;
    struct enum_winstation_reply enum_winstation_reply;
    struct create_desktop_reply create_desktop_reply;
    struct open_desktop_reply open_desktop_reply;
    struct open_input_desktop_reply open_input_desktop_reply;
    struct close_desktop_reply close_desktop_reply;
    struct get_thread_desktop_reply get_thread_desktop_reply;
    struct set_thread_desktop_reply set_thread_desktop_reply;
    struct enum_desktop_reply enum_desktop_reply;
    struct set_user_object_info_reply set_user_object_info_reply;
    struct register_hotkey_reply register_hotkey_reply;
    struct unregister_hotkey_reply unregister_hotkey_reply;
    struct attach_thread_input_reply attach_thread_input_reply;
    struct get_thread_input_reply get_thread_input_reply;
    struct get_last_input_time_reply get_last_input_time_reply;
    struct get_key_state_reply get_key_state_reply;
    struct set_key_state_reply set_key_state_reply;
    struct set_foreground_window_reply set_foreground_window_reply;
    struct set_focus_window_reply set_focus_window_reply;
    struct set_active_window_reply set_active_window_reply;
    struct set_capture_window_reply set_capture_window_reply;
    struct set_caret_window_reply set_caret_window_reply;
    struct set_caret_info_reply set_caret_info_reply;
    struct set_hook_reply set_hook_reply;
    struct remove_hook_reply remove_hook_reply;
    struct start_hook_chain_reply start_hook_chain_reply;
    struct finish_hook_chain_reply finish_hook_chain_reply;
    struct get_hook_info_reply get_hook_info_reply;
    struct create_class_reply create_class_reply;
    struct destroy_class_reply destroy_class_reply;
    struct set_class_info_reply set_class_info_reply;
    struct open_clipboard_reply open_clipboard_reply;
    struct close_clipboard_reply close_clipboard_reply;
    struct empty_clipboard_reply empty_clipboard_reply;
    struct set_clipboard_data_reply set_clipboard_data_reply;
    struct get_clipboard_data_reply get_clipboard_data_reply;
    struct get_clipboard_formats_reply get_clipboard_formats_reply;
    struct enum_clipboard_formats_reply enum_clipboard_formats_reply;
    struct release_clipboard_reply release_clipboard_reply;
    struct get_clipboard_info_reply get_clipboard_info_reply;
    struct set_clipboard_viewer_reply set_clipboard_viewer_reply;
    struct add_clipboard_listener_reply add_clipboard_listener_reply;
    struct remove_clipboard_listener_reply remove_clipboard_listener_reply;
    struct open_token_reply open_token_reply;
    struct set_global_windows_reply set_global_windows_reply;
    struct adjust_token_privileges_reply adjust_token_privileges_reply;
    struct get_token_privileges_reply get_token_privileges_reply;
    struct check_token_privileges_reply check_token_privileges_reply;
    struct duplicate_token_reply duplicate_token_reply;
    struct access_check_reply access_check_reply;
    struct get_token_sid_reply get_token_sid_reply;
    struct get_token_groups_reply get_token_groups_reply;
    struct get_token_default_dacl_reply get_token_default_dacl_reply;
    struct set_token_default_dacl_reply set_token_default_dacl_reply;
    struct set_security_object_reply set_security_object_reply;
    struct get_security_object_reply get_security_object_reply;
    struct get_system_handles_reply get_system_handles_reply;
    struct create_mailslot_reply create_mailslot_reply;
    struct set_mailslot_info_reply set_mailslot_info_reply;
    struct create_directory_reply create_directory_reply;
    struct open_directory_reply open_directory_reply;
    struct get_directory_entry_reply get_directory_entry_reply;
    struct create_symlink_reply create_symlink_reply;
    struct open_symlink_reply open_symlink_reply;
    struct query_symlink_reply query_symlink_reply;
    struct get_object_info_reply get_object_info_reply;
    struct get_object_type_reply get_object_type_reply;
    struct unlink_object_reply unlink_object_reply;
    struct get_token_impersonation_level_reply get_token_impersonation_level_reply;
    struct allocate_locally_unique_id_reply allocate_locally_unique_id_reply;
    struct create_device_manager_reply create_device_manager_reply;
    struct create_device_reply create_device_reply;
    struct delete_device_reply delete_device_reply;
    struct get_next_device_request_reply get_next_device_request_reply;
    struct get_kernel_object_ptr_reply get_kernel_object_ptr_reply;
    struct set_kernel_object_ptr_reply set_kernel_object_ptr_reply;
    struct grab_kernel_object_reply grab_kernel_object_reply;
    struct release_kernel_object_reply release_kernel_object_reply;
    struct get_kernel_object_handle_reply get_kernel_object_handle_reply;
    struct make_process_system_reply make_process_system_reply;
    struct get_token_statistics_reply get_token_statistics_reply;
    struct create_completion_reply create_completion_reply;
    struct open_completion_reply open_completion_reply;
    struct add_completion_reply add_completion_reply;
    struct remove_completion_reply remove_completion_reply;
    struct query_completion_reply query_completion_reply;
    struct set_completion_info_reply set_completion_info_reply;
    struct add_fd_completion_reply add_fd_completion_reply;
    struct set_fd_completion_mode_reply set_fd_completion_mode_reply;
    struct set_fd_disp_info_reply set_fd_disp_info_reply;
    struct set_fd_name_info_reply set_fd_name_info_reply;
    struct get_window_layered_info_reply get_window_layered_info_reply;
    struct set_window_layered_info_reply set_window_layered_info_reply;
    struct alloc_user_handle_reply alloc_user_handle_reply;
    struct free_user_handle_reply free_user_handle_reply;
    struct set_cursor_reply set_cursor_reply;
    struct update_rawinput_devices_reply update_rawinput_devices_reply;
    struct get_suspend_context_reply get_suspend_context_reply;
    struct set_suspend_context_reply set_suspend_context_reply;
    struct create_job_reply create_job_reply;
    struct open_job_reply open_job_reply;
    struct assign_job_reply assign_job_reply;
    struct process_in_job_reply process_in_job_reply;
    struct set_job_limits_reply set_job_limits_reply;
    struct set_job_completion_port_reply set_job_completion_port_reply;
    struct terminate_job_reply terminate_job_reply;
    struct suspend_process_reply suspend_process_reply;
    struct resume_process_reply resume_process_reply;
};


struct __server_iovec
{
    const void* ptr;
    data_size_t size;
};


struct __server_request_info
{
    unsigned int data_count;
    void* reply_data;
    struct __server_iovec data[5];
};


struct cp_info
{
    unsigned int codepage;
    unsigned int char_size;
    WCHAR def_char;
    WCHAR def_unicode_char;
    const char* name;
};


struct sbcs_table
{
    struct cp_info info;
    const WCHAR* cp2uni;
    const WCHAR* cp2uni_glyphs;
    const unsigned char* uni2cp_low;
    const unsigned short* uni2cp_high;
};


struct dbcs_table
{
    struct cp_info info;
    const WCHAR* cp2uni;
    const unsigned char* cp2uni_leadbytes;
    const unsigned short* uni2cp_low;
    const unsigned short* uni2cp_high;
    unsigned char lead_bytes[12];
};


union cptable
{
    struct cp_info info;
    struct sbcs_table sbcs;
    struct dbcs_table dbcs;
};


struct __wine_jmp_buf
{
};


typedef struct __wine_jmp_buf __wine_jmp_buf;

typedef LONG (*__WINE_FILTER) (PEXCEPTION_POINTERS);

typedef LONG (*__WINE_FILTER_CTX) (PEXCEPTION_POINTERS, void*);

typedef void (*__WINE_FINALLY) (BOOL);

typedef void (*__WINE_FINALLY_CTX) (BOOL, void*);

struct __tagWINE_FRAME
{
    EXCEPTION_REGISTRATION_RECORD frame;
    void* ctx;
    __wine_jmp_buf jmp;
    DWORD ExceptionCode;
    const struct __tagWINE_FRAME* ExceptionRecord;
};


typedef struct __tagWINE_FRAME __WINE_FRAME;

enum wine_internal_message
{
    wine_internal_message_DUMMY = 0
};


struct tagUSER_DRIVER
{
    HKL (*pActivateKeyboardLayout) (HKL, UINT);
    void (*pBeep) (void);
    SHORT (*pGetAsyncKeyState) (INT);
    INT (*pGetKeyNameText) (LONG, LPWSTR, INT);
    HKL (*pGetKeyboardLayout) (DWORD);
    UINT (*pGetKeyboardLayoutList) (INT, HKL*);
    BOOL (*pGetKeyboardLayoutName) (LPWSTR);
    HKL (*pLoadKeyboardLayout) (LPCWSTR, UINT);
    UINT (*pMapVirtualKeyEx) (UINT, UINT, HKL);
    BOOL (*pRegisterHotKey) (HWND, UINT, UINT);
    INT (*pToUnicodeEx) (UINT, UINT, const BYTE*, LPWSTR, int, UINT, HKL);
    BOOL (*pUnloadKeyboardLayout) (HKL);
    void (*pUnregisterHotKey) (HWND, UINT, UINT);
    SHORT (*pVkKeyScanEx) (WCHAR, HKL);
    void (*pDestroyCursorIcon) (HCURSOR);
    void (*pSetCursor) (HCURSOR);
    BOOL (*pGetCursorPos) (LPPOINT);
    BOOL (*pSetCursorPos) (INT, INT);
    BOOL (*pClipCursor) (LPCRECT);
    void (*pUpdateClipboard) (void);
    LONG (*pChangeDisplaySettingsEx) (LPCWSTR, LPDEVMODEW, HWND, DWORD, LPVOID);
    BOOL (*pEnumDisplayMonitors) (HDC, LPRECT, MONITORENUMPROC, LPARAM);
    BOOL (*pEnumDisplaySettingsEx) (LPCWSTR, DWORD, LPDEVMODEW, DWORD);
    BOOL (*pGetMonitorInfo) (HMONITOR, MONITORINFO*);
    BOOL (*pCreateDesktopWindow) (HWND);
    BOOL (*pCreateWindow) (HWND);
    void (*pDestroyWindow) (HWND);
    void (*pFlashWindowEx) (FLASHWINFO*);
    void (*pGetDC) (HDC, HWND, HWND, const RECT*, const RECT*, DWORD);
    DWORD (*pMsgWaitForMultipleObjectsEx) (DWORD, const HANDLE*, DWORD, DWORD, DWORD);
    void (*pReleaseDC) (HWND, HDC);
    BOOL (*pScrollDC) (HDC, INT, INT, HRGN);
    void (*pSetCapture) (HWND, UINT);
    void (*pSetFocus) (HWND);
    void (*pSetLayeredWindowAttributes) (HWND, COLORREF, BYTE, DWORD);
    void (*pSetParent) (HWND, HWND, HWND);
    void (*pSetWindowRgn) (HWND, HRGN, BOOL);
    void (*pSetWindowIcon) (HWND, UINT, HICON);
    void (*pSetWindowStyle) (HWND, INT, STYLESTRUCT*);
    void (*pSetWindowText) (HWND, LPCWSTR);
    UINT (*pShowWindow) (HWND, INT, RECT*, UINT);
    LRESULT (*pSysCommand) (HWND, WPARAM, LPARAM);
    BOOL (*pUpdateLayeredWindow) (HWND, const UPDATELAYEREDWINDOWINFO*, const RECT*);
    LRESULT (*pWindowMessage) (HWND, UINT, WPARAM, LPARAM);
    void (*pWindowPosChanging) (HWND, HWND, UINT, const RECT*, const RECT*, RECT*, struct window_surface**);
    void (*pWindowPosChanged) (HWND, HWND, UINT, const RECT*, const RECT*, const RECT*, const RECT*, struct window_surface*);
    BOOL (*pSystemParametersInfo) (UINT, UINT, void*, UINT);
    void (*pThreadDetach) (void);
};


typedef struct tagUSER_DRIVER USER_DRIVER;

enum user_obj_type
{
    user_obj_type_DUMMY = 0
};


struct user_object
{
    HANDLE handle;
    enum user_obj_type type;
};


enum wm_char_mapping
{
    wm_char_mapping_DUMMY = 0
};


struct wm_char_mapping_data
{
    BYTE lead_byte[6];
    MSG get_msg;
};


struct user_thread_info
{
    HANDLE server_queue;
    DWORD wake_mask;
    DWORD changed_mask;
    WORD recursion_count;
    WORD message_count;
    WORD hook_call_depth;
    WORD hook_unicode;
    HHOOK hook;
    UINT active_hooks;
    DPI_AWARENESS dpi_awareness;
    INPUT_MESSAGE_SOURCE msg_source;
    struct received_message_info* receive_info;
    struct wm_char_mapping_data* wmchar_data;
    DWORD GetMessageTimeVal;
    DWORD GetMessagePosVal;
    ULONG_PTR GetMessageExtraInfoVal;
    struct user_key_state_info* key_state;
    HWND top_window;
    HWND msg_window;
    RAWINPUT* rawinput;
};


struct user_key_state_info
{
    UINT time;
    INT counter;
    BYTE state[256];
};


struct hook_extra_info
{
    HHOOK handle;
    LPARAM lparam;
};


typedef LRESULT (*winproc_callback_t) (HWND, UINT, WPARAM, LPARAM, LRESULT*, void*);

struct ICONRESDIR
{
    BYTE bWidth;
    BYTE bHeight;
    BYTE bColorCount;
    BYTE bReserved;
};


typedef struct ICONRESDIR ICONRESDIR;

struct CURSORDIR
{
    WORD wWidth;
    WORD wHeight;
};


typedef struct CURSORDIR CURSORDIR;

struct CURSORICONDIRENTRY
{
    WORD wPlanes;
    WORD wBitCount;
    DWORD dwBytesInRes;
    WORD wResId;
};


typedef struct CURSORICONDIRENTRY CURSORICONDIRENTRY;

struct CURSORICONDIR
{
    WORD idReserved;
    WORD idType;
    WORD idCount;
    CURSORICONDIRENTRY idEntries[1];
};


typedef struct CURSORICONDIR CURSORICONDIR;

struct CURSORICONFILEDIRENTRY
{
    BYTE bWidth;
    BYTE bHeight;
    BYTE bColorCount;
    BYTE bReserved;
    WORD xHotspot;
    WORD yHotspot;
    DWORD dwDIBSize;
    DWORD dwDIBOffset;
};


typedef struct CURSORICONFILEDIRENTRY CURSORICONFILEDIRENTRY;

struct CURSORICONFILEDIR
{
    WORD idReserved;
    WORD idType;
    WORD idCount;
    CURSORICONFILEDIRENTRY idEntries[1];
};


typedef struct CURSORICONFILEDIR CURSORICONFILEDIR;

struct tagWND
{
    struct user_object obj;
    HWND parent;
    HWND owner;
    struct tagCLASS* class;
    struct dce* dce;
    WNDPROC winproc;
    DWORD tid;
    HINSTANCE hInstance;
    RECT client_rect;
    RECT window_rect;
    RECT visible_rect;
    RECT normal_rect;
    POINT min_pos;
    POINT max_pos;
    LPWSTR text;
    void* pScroll;
    DWORD dwStyle;
    DWORD dwExStyle;
    UINT_PTR wIDmenu;
    DWORD helpContext;
    UINT flags;
    HMENU hSysMenu;
    HICON hIcon;
    HICON hIconSmall;
    HICON hIconSmall2;
    UINT dpi;
    DPI_AWARENESS dpi_awareness;
    struct window_surface* surface;
    struct tagDIALOGINFO* dlgInfo;
    int pixel_format;
    int cbWndExtra;
    DWORD_PTR userdata;
    DWORD wExtra[1];
};


typedef struct tagWND WND;

enum builtin_winprocs
{
    builtin_winprocs_DUMMY = 0
};


struct builtin_class_descr
{
    LPCWSTR name;
    UINT style;
    enum builtin_winprocs proc;
    INT extra;
    ULONG_PTR cursor;
    HBRUSH brush;
};


struct wow_handlers16
{
    LRESULT (*button_proc) (HWND, UINT, WPARAM, LPARAM, BOOL);
    LRESULT (*combo_proc) (HWND, UINT, WPARAM, LPARAM, BOOL);
    LRESULT (*edit_proc) (HWND, UINT, WPARAM, LPARAM, BOOL);
    LRESULT (*listbox_proc) (HWND, UINT, WPARAM, LPARAM, BOOL);
    LRESULT (*mdiclient_proc) (HWND, UINT, WPARAM, LPARAM, BOOL);
    LRESULT (*scrollbar_proc) (HWND, UINT, WPARAM, LPARAM, BOOL);
    LRESULT (*static_proc) (HWND, UINT, WPARAM, LPARAM, BOOL);
    DWORD (*wait_message) (DWORD, const HANDLE*, DWORD, DWORD, DWORD);
    HWND (*create_window) (CREATESTRUCTW*, LPCWSTR, HINSTANCE, BOOL);
    LRESULT (*call_window_proc) (HWND, UINT, WPARAM, LPARAM, LRESULT*, void*);
    LRESULT (*call_dialog_proc) (HWND, UINT, WPARAM, LPARAM, LRESULT*, void*);
    void (*free_icon_param) (ULONG_PTR);
};


struct wow_handlers32
{
    LRESULT (*button_proc) (HWND, UINT, WPARAM, LPARAM, BOOL);
    LRESULT (*combo_proc) (HWND, UINT, WPARAM, LPARAM, BOOL);
    LRESULT (*edit_proc) (HWND, UINT, WPARAM, LPARAM, BOOL);
    LRESULT (*listbox_proc) (HWND, UINT, WPARAM, LPARAM, BOOL);
    LRESULT (*mdiclient_proc) (HWND, UINT, WPARAM, LPARAM, BOOL);
    LRESULT (*scrollbar_proc) (HWND, UINT, WPARAM, LPARAM, BOOL);
    LRESULT (*static_proc) (HWND, UINT, WPARAM, LPARAM, BOOL);
    DWORD (*wait_message) (DWORD, const HANDLE*, DWORD, DWORD, DWORD);
    HWND (*create_window) (CREATESTRUCTW*, LPCWSTR, HINSTANCE, BOOL);
    HWND (*get_win_handle) (HWND);
    WNDPROC (*alloc_winproc) (WNDPROC, BOOL);
    struct tagDIALOGINFO* (*get_dialog_info) (HWND, BOOL);
    INT (*dialog_box_loop) (HWND, HWND);
    ULONG_PTR (*get_icon_param) (HICON);
    ULONG_PTR (*set_icon_param) (HICON, ULONG_PTR);
};


struct HEADCOMBO
{
    HWND self;
    HWND owner;
    UINT dwStyle;
    HWND hWndEdit;
    HWND hWndLBox;
    UINT wState;
    HFONT hFont;
    RECT textRect;
    RECT buttonRect;
    RECT droppedRect;
    INT droppedIndex;
    INT fixedOwnerDrawHeight;
    INT droppedWidth;
    INT editHeight;
};


typedef struct HEADCOMBO HEADCOMBO;

typedef struct HEADCOMBO* LPHEADCOMBO;

struct tagDIALOGINFO
{
    HWND hwndFocus;
    HFONT hUserFont;
    HMENU hMenu;
    UINT xBaseUnit;
    UINT yBaseUnit;
    INT idResult;
    UINT flags;
};


typedef struct tagDIALOGINFO DIALOGINFO;

struct MENUITEM
{
    UINT fType;
    UINT fState;
    UINT_PTR wID;
    HMENU hSubMenu;
    HBITMAP hCheckBit;
    HBITMAP hUnCheckBit;
    LPWSTR text;
    ULONG_PTR dwItemData;
    LPWSTR dwTypeData;
    HBITMAP hbmpItem;
    RECT rect;
    UINT xTab;
    SIZE bmpsize;
};


typedef struct MENUITEM MENUITEM;

struct POPUPMENU
{
    struct user_object obj;
    WORD wFlags;
    WORD Width;
    WORD Height;
    UINT nItems;
    HWND hWnd;
    MENUITEM* items;
    UINT FocusedItem;
    HWND hwndOwner;
    BOOL bScrolling;
    UINT nScrollPos;
    UINT nTotalHeight;
    RECT items_rect;
    LONG refcount;
    DWORD dwStyle;
    UINT cyMax;
    HBRUSH hbrBack;
    DWORD dwContextHelpID;
    DWORD dwMenuData;
    HMENU hSysMenuOwner;
    WORD textOffset;
};


typedef struct POPUPMENU POPUPMENU;

typedef struct POPUPMENU* LPPOPUPMENU;

struct MTRACKER
{
    UINT trackFlags;
    HMENU hCurrentMenu;
    HMENU hTopMenu;
    HWND hOwnerWnd;
    POINT pt;
};


typedef struct MTRACKER MTRACKER;

enum hittest
{
    hittest_DUMMY = 0
};


enum tag_SCRIPT_JUSTIFY
{
    tag_SCRIPT_JUSTIFY_DUMMY = 0
};


typedef enum tag_SCRIPT_JUSTIFY SCRIPT_JUSTIFY;

struct tag_SCRIPT_CONTROL
{
    DWORD uDefaultLanguage;
    DWORD fContextDigits;
    DWORD fInvertPreBoundDir;
    DWORD fInvertPostBoundDir;
    DWORD fLinkStringBefore;
    DWORD fLinkStringAfter;
    DWORD fNeutralOverride;
    DWORD fNumericOverride;
    DWORD fLegacyBidiClass;
    DWORD fMergeNeutralItems;
    DWORD fReserved;
};


typedef struct tag_SCRIPT_CONTROL SCRIPT_CONTROL;

struct SCRIPT_PROPERTIES
{
    DWORD langid;
    DWORD fNumeric;
    DWORD fComplex;
    DWORD fNeedsWordBreaking;
    DWORD fNeedsCaretInfo;
    DWORD bCharSet;
    DWORD fControl;
    DWORD fPrivateUseArea;
    DWORD fNeedsCharacterJustify;
    DWORD fInvalidGlyph;
    DWORD fInvalidLogAttr;
    DWORD fCDM;
    DWORD fAmbiguousCharSet;
    DWORD fClusterSizeVaries;
    DWORD fRejectInvalid;
};


typedef struct SCRIPT_PROPERTIES SCRIPT_PROPERTIES;

struct tag_SCRIPT_STATE
{
    WORD uBidiLevel;
    WORD fOverrideDirection;
    WORD fInhibitSymSwap;
    WORD fCharShape;
    WORD fDigitSubstitute;
    WORD fInhibitLigate;
    WORD fDisplayZWG;
    WORD fArabicNumContext;
    WORD fGcpClusters;
    WORD fReserved;
    WORD fEngineReserved;
};


typedef struct tag_SCRIPT_STATE SCRIPT_STATE;

struct tag_SCRIPT_ANALYSIS
{
    WORD eScript;
    WORD fRTL;
    WORD fLayoutRTL;
    WORD fLinkBefore;
    WORD fLinkAfter;
    WORD fLogicalOrder;
    WORD fNoGlyphIndex;
    SCRIPT_STATE s;
};


typedef struct tag_SCRIPT_ANALYSIS SCRIPT_ANALYSIS;

struct tag_SCRIPT_ITEM
{
    int iCharPos;
    SCRIPT_ANALYSIS a;
};


typedef struct tag_SCRIPT_ITEM SCRIPT_ITEM;

struct tag_SCRIPT_DIGITSUBSTITUTE
{
    DWORD NationalDigitLanguage;
    DWORD TraditionalDigitLanguage;
    DWORD DigitSubstitute;
    DWORD dwReserved;
};


typedef struct tag_SCRIPT_DIGITSUBSTITUTE SCRIPT_DIGITSUBSTITUTE;

struct tag_SCRIPT_FONTPROPERTIES
{
    int cBytes;
    WORD wgBlank;
    WORD wgDefault;
    WORD wgInvalid;
    WORD wgKashida;
    int iKashidaWidth;
};


typedef struct tag_SCRIPT_FONTPROPERTIES SCRIPT_FONTPROPERTIES;

struct tag_SCRIPT_TABDEF
{
    int cTabStops;
    int iScale;
    int* pTabStops;
    int iTabOrigin;
};


typedef struct tag_SCRIPT_TABDEF SCRIPT_TABDEF;

struct tag_SCRIPT_VISATTR
{
    WORD uJustification;
    WORD fClusterStart;
    WORD fDiacritic;
    WORD fZeroWidth;
    WORD fReserved;
    WORD fShapeReserved;
};


typedef struct tag_SCRIPT_VISATTR SCRIPT_VISATTR;

struct tag_SCRIPT_LOGATTR
{
    BYTE fSoftBreak;
    BYTE fWhiteSpace;
    BYTE fCharStop;
    BYTE fWordStop;
    BYTE fInvalid;
    BYTE fReserved;
};


typedef struct tag_SCRIPT_LOGATTR SCRIPT_LOGATTR;

typedef void* SCRIPT_CACHE;

typedef void* SCRIPT_STRING_ANALYSIS;

struct tagGOFFSET
{
    LONG du;
    LONG dv;
};


typedef struct tagGOFFSET GOFFSET;

typedef ULONG OPENTYPE_TAG;

struct tagOPENTYPE_FEATURE_RECORD
{
    OPENTYPE_TAG tagFeature;
    LONG lParameter;
};


typedef struct tagOPENTYPE_FEATURE_RECORD OPENTYPE_FEATURE_RECORD;

struct tagSCRIPT_GLYPHPROP
{
    SCRIPT_VISATTR sva;
    WORD reserved;
};


typedef struct tagSCRIPT_GLYPHPROP SCRIPT_GLYPHPROP;

struct tagSCRIPT_CHARPROP
{
    WORD fCanGlyphAlone;
    WORD reserved;
};


typedef struct tagSCRIPT_CHARPROP SCRIPT_CHARPROP;

struct tagTEXTRANGE_PROPERTIES
{
    OPENTYPE_FEATURE_RECORD* potfRecords;
    INT cotfRecords;
};


typedef struct tagTEXTRANGE_PROPERTIES TEXTRANGE_PROPERTIES;

struct tag_ellipsis_data
{
    int before;
    int len;
    int under;
    int after;
};


typedef struct tag_ellipsis_data ellipsis_data;

static WINAPI BOOL (*pTrackPopupMenuEx)(HMENU hMenu, UINT wFlags, INT x, INT y, HWND hWnd, LPTPMPARAMS lpTpm);
static WINAPI BOOL (*pTrackPopupMenu)(HMENU hMenu, UINT wFlags, INT x, INT y, INT nReserved, HWND hWnd, const RECT * lpRect);
static WINAPI BOOL (*pChangeMenuA)(HMENU hMenu, UINT pos, LPCSTR data, UINT id, UINT flags);
static WINAPI BOOL (*pChangeMenuW)(HMENU hMenu, UINT pos, LPCWSTR data, UINT id, UINT flags);
static WINAPI DWORD (*pCheckMenuItem)(HMENU hMenu, UINT id, UINT flags);
static WINAPI BOOL (*pEnableMenuItem)(HMENU hMenu, UINT id, UINT wFlags);
static WINAPI INT (*pGetMenuStringA)(HMENU hMenu, UINT wItemID, LPSTR str, INT nMaxSiz, UINT wFlags);
static WINAPI INT (*pGetMenuStringW)(HMENU hMenu, UINT wItemID, LPWSTR str, INT nMaxSiz, UINT wFlags);
static WINAPI BOOL (*pHiliteMenuItem)(HWND hWnd, HMENU hMenu, UINT wItemID, UINT wHilite);
static WINAPI UINT (*pGetMenuState)(HMENU hMenu, UINT wItemID, UINT wFlags);
static WINAPI INT (*pGetMenuItemCount)(HMENU hMenu);
static WINAPI UINT (*pGetMenuItemID)(HMENU hMenu, INT nPos);
static WINAPI BOOL (*pInsertMenuW)(HMENU hMenu, UINT pos, UINT flags, UINT_PTR id, LPCWSTR str);
static WINAPI BOOL (*pInsertMenuA)(HMENU hMenu, UINT pos, UINT flags, UINT_PTR id, LPCSTR str);
static WINAPI BOOL (*pAppendMenuA)(HMENU hMenu, UINT flags, UINT_PTR id, LPCSTR data);
static WINAPI BOOL (*pAppendMenuW)(HMENU hMenu, UINT flags, UINT_PTR id, LPCWSTR data);
static WINAPI BOOL (*pRemoveMenu)(HMENU hMenu, UINT id, UINT flags);
static WINAPI BOOL (*pDeleteMenu)(HMENU hMenu, UINT id, UINT flags);
static WINAPI BOOL (*pModifyMenuW)(HMENU hMenu, UINT pos, UINT flags, UINT_PTR id, LPCWSTR str);
static WINAPI BOOL (*pModifyMenuA)(HMENU hMenu, UINT pos, UINT flags, UINT_PTR id, LPCSTR str);
static WINAPI HMENU (*pCreatePopupMenu)(void);
static WINAPI DWORD (*pGetMenuCheckMarkDimensions)(void);
static WINAPI BOOL (*pSetMenuItemBitmaps)(HMENU hMenu, UINT nPos, UINT wFlags, HBITMAP hNewUnCheck, HBITMAP hNewCheck);
static WINAPI HMENU (*pCreateMenu)(void);
static WINAPI BOOL (*pDestroyMenu)(HMENU hMenu);
static WINAPI HMENU (*pGetSystemMenu)(HWND hWnd, BOOL bRevert);
static WINAPI BOOL (*pSetSystemMenu)(HWND hwnd, HMENU hMenu);
static WINAPI HMENU (*pGetMenu)(HWND hWnd);
static WINAPI BOOL (*pGetMenuBarInfo)(HWND hwnd, LONG idObject, LONG idItem, PMENUBARINFO pmbi);
static WINAPI BOOL (*pSetMenu)(HWND hWnd, HMENU hMenu);
static WINAPI HMENU (*pGetSubMenu)(HMENU hMenu, INT nPos);
static WINAPI BOOL (*pDrawMenuBar)(HWND hWnd);
static WINAPI DWORD (*pDrawMenuBarTemp)(HWND hwnd, HDC hDC, LPRECT lprect, HMENU hMenu, HFONT hFont);
static WINAPI BOOL (*pEndMenu)(void);
static WINAPI HMENU (*pLoadMenuA)(HINSTANCE instance, LPCSTR name);
static WINAPI HMENU (*pLoadMenuW)(HINSTANCE instance, LPCWSTR name);
static WINAPI HMENU (*pLoadMenuIndirectW)(LPCVOID template);
static WINAPI HMENU (*pLoadMenuIndirectA)(LPCVOID template);
static WINAPI BOOL (*pIsMenu)(HMENU hmenu);
static WINAPI BOOL (*pGetMenuItemInfoA)(HMENU hmenu, UINT item, BOOL bypos, LPMENUITEMINFOA lpmii);
static WINAPI BOOL (*pGetMenuItemInfoW)(HMENU hmenu, UINT item, BOOL bypos, LPMENUITEMINFOW lpmii);
static WINAPI BOOL (*pSetMenuItemInfoA)(HMENU hmenu, UINT item, BOOL bypos, const MENUITEMINFOA * lpmii);
static WINAPI BOOL (*pSetMenuItemInfoW)(HMENU hmenu, UINT item, BOOL bypos, const MENUITEMINFOW * lpmii);
static WINAPI BOOL (*pSetMenuDefaultItem)(HMENU hmenu, UINT uItem, UINT bypos);
static WINAPI UINT (*pGetMenuDefaultItem)(HMENU hmenu, UINT bypos, UINT flags);
static WINAPI BOOL (*pInsertMenuItemA)(HMENU hMenu, UINT uItem, BOOL bypos, const MENUITEMINFOA * lpmii);
static WINAPI BOOL (*pInsertMenuItemW)(HMENU hMenu, UINT uItem, BOOL bypos, const MENUITEMINFOW * lpmii);
static WINAPI BOOL (*pCheckMenuRadioItem)(HMENU hMenu, UINT first, UINT last, UINT check, UINT flags);
static WINAPI BOOL (*pGetMenuItemRect)(HWND hwnd, HMENU hMenu, UINT uItem, RECT * rect);
static WINAPI BOOL (*pSetMenuInfo)(HMENU hMenu, LPCMENUINFO lpmi);
static WINAPI BOOL (*pGetMenuInfo)(HMENU hMenu, LPMENUINFO lpmi);
static WINAPI BOOL (*pSetMenuContextHelpId)(HMENU hMenu, DWORD dwContextHelpID);
static WINAPI DWORD (*pGetMenuContextHelpId)(HMENU hMenu);
static WINAPI INT (*pMenuItemFromPoint)(HWND hWnd, HMENU hMenu, POINT ptScreen);
static WINAPI DWORD (*pCalcMenuBar)(HWND hwnd, DWORD left, DWORD right, DWORD top, RECT * rect);
static WINAPI INT (*pTranslateAcceleratorA)(HWND hWnd, HACCEL hAccel, LPMSG msg);
static WINAPI INT (*pTranslateAcceleratorW)(HWND hWnd, HACCEL hAccel, LPMSG msg);

extern WINAPI BOOL wine32b_TrackPopupMenuEx(HMENU hMenu, UINT wFlags, INT x, INT y, HWND hWnd, LPTPMPARAMS lpTpm)
{
	TRACE("Enter TrackPopupMenuEx\n");
	return pTrackPopupMenuEx(hMenu, wFlags, x, y, hWnd, lpTpm);
}

extern WINAPI void wine32a_TrackPopupMenuEx(void);
__ASM_GLOBAL_FUNC(wine32a_TrackPopupMenuEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TrackPopupMenuEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $24, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_TrackPopupMenu(HMENU hMenu, UINT wFlags, INT x, INT y, INT nReserved, HWND hWnd, const RECT * lpRect)
{
	TRACE("Enter TrackPopupMenu\n");
	return pTrackPopupMenu(hMenu, wFlags, x, y, nReserved, hWnd, lpRect);
}

extern WINAPI void wine32a_TrackPopupMenu(void);
__ASM_GLOBAL_FUNC(wine32a_TrackPopupMenu,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TrackPopupMenu") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $28, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_ChangeMenuA(HMENU hMenu, UINT pos, LPCSTR data, UINT id, UINT flags)
{
	TRACE("Enter ChangeMenuA\n");
	return pChangeMenuA(hMenu, pos, data, id, flags);
}

extern WINAPI void wine32a_ChangeMenuA(void);
__ASM_GLOBAL_FUNC(wine32a_ChangeMenuA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ChangeMenuA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_ChangeMenuW(HMENU hMenu, UINT pos, LPCWSTR data, UINT id, UINT flags)
{
	TRACE("Enter ChangeMenuW\n");
	return pChangeMenuW(hMenu, pos, data, id, flags);
}

extern WINAPI void wine32a_ChangeMenuW(void);
__ASM_GLOBAL_FUNC(wine32a_ChangeMenuW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ChangeMenuW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_CheckMenuItem(HMENU hMenu, UINT id, UINT flags)
{
	TRACE("Enter CheckMenuItem\n");
	return pCheckMenuItem(hMenu, id, flags);
}

extern WINAPI void wine32a_CheckMenuItem(void);
__ASM_GLOBAL_FUNC(wine32a_CheckMenuItem,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CheckMenuItem") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_EnableMenuItem(HMENU hMenu, UINT id, UINT wFlags)
{
	TRACE("Enter EnableMenuItem\n");
	return pEnableMenuItem(hMenu, id, wFlags);
}

extern WINAPI void wine32a_EnableMenuItem(void);
__ASM_GLOBAL_FUNC(wine32a_EnableMenuItem,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnableMenuItem") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_GetMenuStringA(HMENU hMenu, UINT wItemID, LPSTR str, INT nMaxSiz, UINT wFlags)
{
	TRACE("Enter GetMenuStringA\n");
	return pGetMenuStringA(hMenu, wItemID, str, nMaxSiz, wFlags);
}

extern WINAPI void wine32a_GetMenuStringA(void);
__ASM_GLOBAL_FUNC(wine32a_GetMenuStringA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetMenuStringA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_GetMenuStringW(HMENU hMenu, UINT wItemID, LPWSTR str, INT nMaxSiz, UINT wFlags)
{
	TRACE("Enter GetMenuStringW\n");
	return pGetMenuStringW(hMenu, wItemID, str, nMaxSiz, wFlags);
}

extern WINAPI void wine32a_GetMenuStringW(void);
__ASM_GLOBAL_FUNC(wine32a_GetMenuStringW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetMenuStringW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_HiliteMenuItem(HWND hWnd, HMENU hMenu, UINT wItemID, UINT wHilite)
{
	TRACE("Enter HiliteMenuItem\n");
	return pHiliteMenuItem(hWnd, hMenu, wItemID, wHilite);
}

extern WINAPI void wine32a_HiliteMenuItem(void);
__ASM_GLOBAL_FUNC(wine32a_HiliteMenuItem,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_HiliteMenuItem") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_GetMenuState(HMENU hMenu, UINT wItemID, UINT wFlags)
{
	TRACE("Enter GetMenuState\n");
	return pGetMenuState(hMenu, wItemID, wFlags);
}

extern WINAPI void wine32a_GetMenuState(void);
__ASM_GLOBAL_FUNC(wine32a_GetMenuState,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetMenuState") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_GetMenuItemCount(HMENU hMenu)
{
	TRACE("Enter GetMenuItemCount\n");
	return pGetMenuItemCount(hMenu);
}

extern WINAPI void wine32a_GetMenuItemCount(void);
__ASM_GLOBAL_FUNC(wine32a_GetMenuItemCount,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetMenuItemCount") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_GetMenuItemID(HMENU hMenu, INT nPos)
{
	TRACE("Enter GetMenuItemID\n");
	return pGetMenuItemID(hMenu, nPos);
}

extern WINAPI void wine32a_GetMenuItemID(void);
__ASM_GLOBAL_FUNC(wine32a_GetMenuItemID,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetMenuItemID") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_InsertMenuW(HMENU hMenu, UINT pos, UINT flags, UINT_PTR id, LPCWSTR str)
{
	TRACE("Enter InsertMenuW\n");
	return pInsertMenuW(hMenu, pos, flags, id, str);
}

extern WINAPI void wine32a_InsertMenuW(void);
__ASM_GLOBAL_FUNC(wine32a_InsertMenuW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_InsertMenuW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_InsertMenuA(HMENU hMenu, UINT pos, UINT flags, UINT_PTR id, LPCSTR str)
{
	TRACE("Enter InsertMenuA\n");
	return pInsertMenuA(hMenu, pos, flags, id, str);
}

extern WINAPI void wine32a_InsertMenuA(void);
__ASM_GLOBAL_FUNC(wine32a_InsertMenuA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_InsertMenuA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_AppendMenuA(HMENU hMenu, UINT flags, UINT_PTR id, LPCSTR data)
{
	TRACE("Enter AppendMenuA\n");
	return pAppendMenuA(hMenu, flags, id, data);
}

extern WINAPI void wine32a_AppendMenuA(void);
__ASM_GLOBAL_FUNC(wine32a_AppendMenuA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_AppendMenuA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_AppendMenuW(HMENU hMenu, UINT flags, UINT_PTR id, LPCWSTR data)
{
	TRACE("Enter AppendMenuW\n");
	return pAppendMenuW(hMenu, flags, id, data);
}

extern WINAPI void wine32a_AppendMenuW(void);
__ASM_GLOBAL_FUNC(wine32a_AppendMenuW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_AppendMenuW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_RemoveMenu(HMENU hMenu, UINT id, UINT flags)
{
	TRACE("Enter RemoveMenu\n");
	return pRemoveMenu(hMenu, id, flags);
}

extern WINAPI void wine32a_RemoveMenu(void);
__ASM_GLOBAL_FUNC(wine32a_RemoveMenu,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RemoveMenu") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_DeleteMenu(HMENU hMenu, UINT id, UINT flags)
{
	TRACE("Enter DeleteMenu\n");
	return pDeleteMenu(hMenu, id, flags);
}

extern WINAPI void wine32a_DeleteMenu(void);
__ASM_GLOBAL_FUNC(wine32a_DeleteMenu,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DeleteMenu") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_ModifyMenuW(HMENU hMenu, UINT pos, UINT flags, UINT_PTR id, LPCWSTR str)
{
	TRACE("Enter ModifyMenuW\n");
	return pModifyMenuW(hMenu, pos, flags, id, str);
}

extern WINAPI void wine32a_ModifyMenuW(void);
__ASM_GLOBAL_FUNC(wine32a_ModifyMenuW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ModifyMenuW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_ModifyMenuA(HMENU hMenu, UINT pos, UINT flags, UINT_PTR id, LPCSTR str)
{
	TRACE("Enter ModifyMenuA\n");
	return pModifyMenuA(hMenu, pos, flags, id, str);
}

extern WINAPI void wine32a_ModifyMenuA(void);
__ASM_GLOBAL_FUNC(wine32a_ModifyMenuA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ModifyMenuA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HMENU wine32b_CreatePopupMenu(void)
{
	TRACE("Enter CreatePopupMenu\n");
	return pCreatePopupMenu();
}

extern WINAPI void wine32a_CreatePopupMenu(void);
__ASM_GLOBAL_FUNC(wine32a_CreatePopupMenu,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreatePopupMenu") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_GetMenuCheckMarkDimensions(void)
{
	TRACE("Enter GetMenuCheckMarkDimensions\n");
	return pGetMenuCheckMarkDimensions();
}

extern WINAPI void wine32a_GetMenuCheckMarkDimensions(void);
__ASM_GLOBAL_FUNC(wine32a_GetMenuCheckMarkDimensions,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetMenuCheckMarkDimensions") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetMenuItemBitmaps(HMENU hMenu, UINT nPos, UINT wFlags, HBITMAP hNewUnCheck, HBITMAP hNewCheck)
{
	TRACE("Enter SetMenuItemBitmaps\n");
	return pSetMenuItemBitmaps(hMenu, nPos, wFlags, hNewUnCheck, hNewCheck);
}

extern WINAPI void wine32a_SetMenuItemBitmaps(void);
__ASM_GLOBAL_FUNC(wine32a_SetMenuItemBitmaps,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetMenuItemBitmaps") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HMENU wine32b_CreateMenu(void)
{
	TRACE("Enter CreateMenu\n");
	return pCreateMenu();
}

extern WINAPI void wine32a_CreateMenu(void);
__ASM_GLOBAL_FUNC(wine32a_CreateMenu,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateMenu") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_DestroyMenu(HMENU hMenu)
{
	TRACE("Enter DestroyMenu\n");
	return pDestroyMenu(hMenu);
}

extern WINAPI void wine32a_DestroyMenu(void);
__ASM_GLOBAL_FUNC(wine32a_DestroyMenu,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DestroyMenu") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HMENU wine32b_GetSystemMenu(HWND hWnd, BOOL bRevert)
{
	TRACE("Enter GetSystemMenu\n");
	return pGetSystemMenu(hWnd, bRevert);
}

extern WINAPI void wine32a_GetSystemMenu(void);
__ASM_GLOBAL_FUNC(wine32a_GetSystemMenu,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetSystemMenu") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetSystemMenu(HWND hwnd, HMENU hMenu)
{
	TRACE("Enter SetSystemMenu\n");
	return pSetSystemMenu(hwnd, hMenu);
}

extern WINAPI void wine32a_SetSystemMenu(void);
__ASM_GLOBAL_FUNC(wine32a_SetSystemMenu,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetSystemMenu") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HMENU wine32b_GetMenu(HWND hWnd)
{
	TRACE("Enter GetMenu\n");
	return pGetMenu(hWnd);
}

extern WINAPI void wine32a_GetMenu(void);
__ASM_GLOBAL_FUNC(wine32a_GetMenu,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetMenu") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetMenuBarInfo(HWND hwnd, LONG idObject, LONG idItem, PMENUBARINFO pmbi)
{
	TRACE("Enter GetMenuBarInfo\n");
	return pGetMenuBarInfo(hwnd, idObject, idItem, pmbi);
}

extern WINAPI void wine32a_GetMenuBarInfo(void);
__ASM_GLOBAL_FUNC(wine32a_GetMenuBarInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetMenuBarInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetMenu(HWND hWnd, HMENU hMenu)
{
	TRACE("Enter SetMenu\n");
	return pSetMenu(hWnd, hMenu);
}

extern WINAPI void wine32a_SetMenu(void);
__ASM_GLOBAL_FUNC(wine32a_SetMenu,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetMenu") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HMENU wine32b_GetSubMenu(HMENU hMenu, INT nPos)
{
	TRACE("Enter GetSubMenu\n");
	return pGetSubMenu(hMenu, nPos);
}

extern WINAPI void wine32a_GetSubMenu(void);
__ASM_GLOBAL_FUNC(wine32a_GetSubMenu,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetSubMenu") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_DrawMenuBar(HWND hWnd)
{
	TRACE("Enter DrawMenuBar\n");
	return pDrawMenuBar(hWnd);
}

extern WINAPI void wine32a_DrawMenuBar(void);
__ASM_GLOBAL_FUNC(wine32a_DrawMenuBar,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DrawMenuBar") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_DrawMenuBarTemp(HWND hwnd, HDC hDC, LPRECT lprect, HMENU hMenu, HFONT hFont)
{
	TRACE("Enter DrawMenuBarTemp\n");
	return pDrawMenuBarTemp(hwnd, hDC, lprect, hMenu, hFont);
}

extern WINAPI void wine32a_DrawMenuBarTemp(void);
__ASM_GLOBAL_FUNC(wine32a_DrawMenuBarTemp,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DrawMenuBarTemp") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_EndMenu(void)
{
	TRACE("Enter EndMenu\n");
	return pEndMenu();
}

extern WINAPI void wine32a_EndMenu(void);
__ASM_GLOBAL_FUNC(wine32a_EndMenu,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EndMenu") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HMENU wine32b_LoadMenuA(HINSTANCE instance, LPCSTR name)
{
	TRACE("Enter LoadMenuA\n");
	return pLoadMenuA(instance, name);
}

extern WINAPI void wine32a_LoadMenuA(void);
__ASM_GLOBAL_FUNC(wine32a_LoadMenuA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LoadMenuA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HMENU wine32b_LoadMenuW(HINSTANCE instance, LPCWSTR name)
{
	TRACE("Enter LoadMenuW\n");
	return pLoadMenuW(instance, name);
}

extern WINAPI void wine32a_LoadMenuW(void);
__ASM_GLOBAL_FUNC(wine32a_LoadMenuW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LoadMenuW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HMENU wine32b_LoadMenuIndirectW(LPCVOID template)
{
	TRACE("Enter LoadMenuIndirectW\n");
	return pLoadMenuIndirectW(template);
}

extern WINAPI void wine32a_LoadMenuIndirectW(void);
__ASM_GLOBAL_FUNC(wine32a_LoadMenuIndirectW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LoadMenuIndirectW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HMENU wine32b_LoadMenuIndirectA(LPCVOID template)
{
	TRACE("Enter LoadMenuIndirectA\n");
	return pLoadMenuIndirectA(template);
}

extern WINAPI void wine32a_LoadMenuIndirectA(void);
__ASM_GLOBAL_FUNC(wine32a_LoadMenuIndirectA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LoadMenuIndirectA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_IsMenu(HMENU hmenu)
{
	TRACE("Enter IsMenu\n");
	return pIsMenu(hmenu);
}

extern WINAPI void wine32a_IsMenu(void);
__ASM_GLOBAL_FUNC(wine32a_IsMenu,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsMenu") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetMenuItemInfoA(HMENU hmenu, UINT item, BOOL bypos, LPMENUITEMINFOA lpmii)
{
	TRACE("Enter GetMenuItemInfoA\n");
	return pGetMenuItemInfoA(hmenu, item, bypos, lpmii);
}

extern WINAPI void wine32a_GetMenuItemInfoA(void);
__ASM_GLOBAL_FUNC(wine32a_GetMenuItemInfoA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetMenuItemInfoA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetMenuItemInfoW(HMENU hmenu, UINT item, BOOL bypos, LPMENUITEMINFOW lpmii)
{
	TRACE("Enter GetMenuItemInfoW\n");
	return pGetMenuItemInfoW(hmenu, item, bypos, lpmii);
}

extern WINAPI void wine32a_GetMenuItemInfoW(void);
__ASM_GLOBAL_FUNC(wine32a_GetMenuItemInfoW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetMenuItemInfoW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetMenuItemInfoA(HMENU hmenu, UINT item, BOOL bypos, const MENUITEMINFOA * lpmii)
{
	TRACE("Enter SetMenuItemInfoA\n");
	return pSetMenuItemInfoA(hmenu, item, bypos, lpmii);
}

extern WINAPI void wine32a_SetMenuItemInfoA(void);
__ASM_GLOBAL_FUNC(wine32a_SetMenuItemInfoA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetMenuItemInfoA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetMenuItemInfoW(HMENU hmenu, UINT item, BOOL bypos, const MENUITEMINFOW * lpmii)
{
	TRACE("Enter SetMenuItemInfoW\n");
	return pSetMenuItemInfoW(hmenu, item, bypos, lpmii);
}

extern WINAPI void wine32a_SetMenuItemInfoW(void);
__ASM_GLOBAL_FUNC(wine32a_SetMenuItemInfoW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetMenuItemInfoW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetMenuDefaultItem(HMENU hmenu, UINT uItem, UINT bypos)
{
	TRACE("Enter SetMenuDefaultItem\n");
	return pSetMenuDefaultItem(hmenu, uItem, bypos);
}

extern WINAPI void wine32a_SetMenuDefaultItem(void);
__ASM_GLOBAL_FUNC(wine32a_SetMenuDefaultItem,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetMenuDefaultItem") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_GetMenuDefaultItem(HMENU hmenu, UINT bypos, UINT flags)
{
	TRACE("Enter GetMenuDefaultItem\n");
	return pGetMenuDefaultItem(hmenu, bypos, flags);
}

extern WINAPI void wine32a_GetMenuDefaultItem(void);
__ASM_GLOBAL_FUNC(wine32a_GetMenuDefaultItem,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetMenuDefaultItem") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_InsertMenuItemA(HMENU hMenu, UINT uItem, BOOL bypos, const MENUITEMINFOA * lpmii)
{
	TRACE("Enter InsertMenuItemA\n");
	return pInsertMenuItemA(hMenu, uItem, bypos, lpmii);
}

extern WINAPI void wine32a_InsertMenuItemA(void);
__ASM_GLOBAL_FUNC(wine32a_InsertMenuItemA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_InsertMenuItemA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_InsertMenuItemW(HMENU hMenu, UINT uItem, BOOL bypos, const MENUITEMINFOW * lpmii)
{
	TRACE("Enter InsertMenuItemW\n");
	return pInsertMenuItemW(hMenu, uItem, bypos, lpmii);
}

extern WINAPI void wine32a_InsertMenuItemW(void);
__ASM_GLOBAL_FUNC(wine32a_InsertMenuItemW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_InsertMenuItemW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_CheckMenuRadioItem(HMENU hMenu, UINT first, UINT last, UINT check, UINT flags)
{
	TRACE("Enter CheckMenuRadioItem\n");
	return pCheckMenuRadioItem(hMenu, first, last, check, flags);
}

extern WINAPI void wine32a_CheckMenuRadioItem(void);
__ASM_GLOBAL_FUNC(wine32a_CheckMenuRadioItem,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CheckMenuRadioItem") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetMenuItemRect(HWND hwnd, HMENU hMenu, UINT uItem, RECT * rect)
{
	TRACE("Enter GetMenuItemRect\n");
	return pGetMenuItemRect(hwnd, hMenu, uItem, rect);
}

extern WINAPI void wine32a_GetMenuItemRect(void);
__ASM_GLOBAL_FUNC(wine32a_GetMenuItemRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetMenuItemRect") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetMenuInfo(HMENU hMenu, LPCMENUINFO lpmi)
{
	TRACE("Enter SetMenuInfo\n");
	return pSetMenuInfo(hMenu, lpmi);
}

extern WINAPI void wine32a_SetMenuInfo(void);
__ASM_GLOBAL_FUNC(wine32a_SetMenuInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetMenuInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetMenuInfo(HMENU hMenu, LPMENUINFO lpmi)
{
	TRACE("Enter GetMenuInfo\n");
	return pGetMenuInfo(hMenu, lpmi);
}

extern WINAPI void wine32a_GetMenuInfo(void);
__ASM_GLOBAL_FUNC(wine32a_GetMenuInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetMenuInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetMenuContextHelpId(HMENU hMenu, DWORD dwContextHelpID)
{
	TRACE("Enter SetMenuContextHelpId\n");
	return pSetMenuContextHelpId(hMenu, dwContextHelpID);
}

extern WINAPI void wine32a_SetMenuContextHelpId(void);
__ASM_GLOBAL_FUNC(wine32a_SetMenuContextHelpId,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetMenuContextHelpId") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_GetMenuContextHelpId(HMENU hMenu)
{
	TRACE("Enter GetMenuContextHelpId\n");
	return pGetMenuContextHelpId(hMenu);
}

extern WINAPI void wine32a_GetMenuContextHelpId(void);
__ASM_GLOBAL_FUNC(wine32a_GetMenuContextHelpId,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetMenuContextHelpId") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_MenuItemFromPoint(HWND hWnd, HMENU hMenu, POINT ptScreen)
{
	TRACE("Enter MenuItemFromPoint\n");
	return pMenuItemFromPoint(hWnd, hMenu, ptScreen);
}

extern WINAPI void wine32a_MenuItemFromPoint(void);
__ASM_GLOBAL_FUNC(wine32a_MenuItemFromPoint,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_MenuItemFromPoint") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_CalcMenuBar(HWND hwnd, DWORD left, DWORD right, DWORD top, RECT * rect)
{
	TRACE("Enter CalcMenuBar\n");
	return pCalcMenuBar(hwnd, left, right, top, rect);
}

extern WINAPI void wine32a_CalcMenuBar(void);
__ASM_GLOBAL_FUNC(wine32a_CalcMenuBar,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CalcMenuBar") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_TranslateAcceleratorA(HWND hWnd, HACCEL hAccel, LPMSG msg)
{
	TRACE("Enter TranslateAcceleratorA\n");
	return pTranslateAcceleratorA(hWnd, hAccel, msg);
}

extern WINAPI void wine32a_TranslateAcceleratorA(void);
__ASM_GLOBAL_FUNC(wine32a_TranslateAcceleratorA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TranslateAcceleratorA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_TranslateAcceleratorW(HWND hWnd, HACCEL hAccel, LPMSG msg)
{
	TRACE("Enter TranslateAcceleratorW\n");
	return pTranslateAcceleratorW(hWnd, hAccel, msg);
}

extern WINAPI void wine32a_TranslateAcceleratorW(void);
__ASM_GLOBAL_FUNC(wine32a_TranslateAcceleratorW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TranslateAcceleratorW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

static WINAPI INT (*pDrawTextExW)(HDC hdc, LPWSTR str, INT i_count, LPRECT rect, UINT flags, LPDRAWTEXTPARAMS dtp);
static WINAPI INT (*pDrawTextExA)(HDC hdc, LPSTR str, INT count, LPRECT rect, UINT flags, LPDRAWTEXTPARAMS dtp);
static WINAPI INT (*pDrawTextW)(HDC hdc, LPCWSTR str, INT count, LPRECT rect, UINT flags);
static WINAPI INT (*pDrawTextA)(HDC hdc, LPCSTR str, INT count, LPRECT rect, UINT flags);
static WINAPI BOOL (*pGrayStringA)(HDC hdc, HBRUSH hbr, GRAYSTRINGPROC gsprc, LPARAM lParam, INT cch, INT x, INT y, INT cx, INT cy);
static WINAPI BOOL (*pGrayStringW)(HDC hdc, HBRUSH hbr, GRAYSTRINGPROC gsprc, LPARAM lParam, INT cch, INT x, INT y, INT cx, INT cy);
static WINAPI LONG (*pTabbedTextOutA)(HDC hdc, INT x, INT y, LPCSTR lpstr, INT count, INT cTabStops, const INT * lpTabPos, INT nTabOrg);
static WINAPI LONG (*pTabbedTextOutW)(HDC hdc, INT x, INT y, LPCWSTR str, INT count, INT cTabStops, const INT * lpTabPos, INT nTabOrg);
static WINAPI DWORD (*pGetTabbedTextExtentA)(HDC hdc, LPCSTR lpstr, INT count, INT cTabStops, const INT * lpTabPos);
static WINAPI DWORD (*pGetTabbedTextExtentW)(HDC hdc, LPCWSTR lpstr, INT count, INT cTabStops, const INT * lpTabPos);

extern WINAPI INT wine32b_DrawTextExW(HDC hdc, LPWSTR str, INT i_count, LPRECT rect, UINT flags, LPDRAWTEXTPARAMS dtp)
{
	TRACE("Enter DrawTextExW\n");
	return pDrawTextExW(hdc, str, i_count, rect, flags, dtp);
}

extern WINAPI void wine32a_DrawTextExW(void);
__ASM_GLOBAL_FUNC(wine32a_DrawTextExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DrawTextExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $24, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_DrawTextExA(HDC hdc, LPSTR str, INT count, LPRECT rect, UINT flags, LPDRAWTEXTPARAMS dtp)
{
	TRACE("Enter DrawTextExA\n");
	return pDrawTextExA(hdc, str, count, rect, flags, dtp);
}

extern WINAPI void wine32a_DrawTextExA(void);
__ASM_GLOBAL_FUNC(wine32a_DrawTextExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DrawTextExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $24, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_DrawTextW(HDC hdc, LPCWSTR str, INT count, LPRECT rect, UINT flags)
{
	TRACE("Enter DrawTextW\n");
	return pDrawTextW(hdc, str, count, rect, flags);
}

extern WINAPI void wine32a_DrawTextW(void);
__ASM_GLOBAL_FUNC(wine32a_DrawTextW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DrawTextW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_DrawTextA(HDC hdc, LPCSTR str, INT count, LPRECT rect, UINT flags)
{
	TRACE("Enter DrawTextA\n");
	return pDrawTextA(hdc, str, count, rect, flags);
}

extern WINAPI void wine32a_DrawTextA(void);
__ASM_GLOBAL_FUNC(wine32a_DrawTextA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DrawTextA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GrayStringA(HDC hdc, HBRUSH hbr, GRAYSTRINGPROC gsprc, LPARAM lParam, INT cch, INT x, INT y, INT cx, INT cy)
{
	TRACE("Enter GrayStringA\n");
	return pGrayStringA(hdc, hbr, gsprc, lParam, cch, x, y, cx, cy);
}

extern WINAPI void wine32a_GrayStringA(void);
__ASM_GLOBAL_FUNC(wine32a_GrayStringA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GrayStringA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $36, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GrayStringW(HDC hdc, HBRUSH hbr, GRAYSTRINGPROC gsprc, LPARAM lParam, INT cch, INT x, INT y, INT cx, INT cy)
{
	TRACE("Enter GrayStringW\n");
	return pGrayStringW(hdc, hbr, gsprc, lParam, cch, x, y, cx, cy);
}

extern WINAPI void wine32a_GrayStringW(void);
__ASM_GLOBAL_FUNC(wine32a_GrayStringW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GrayStringW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $36, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_TabbedTextOutA(HDC hdc, INT x, INT y, LPCSTR lpstr, INT count, INT cTabStops, const INT * lpTabPos, INT nTabOrg)
{
	TRACE("Enter TabbedTextOutA\n");
	return pTabbedTextOutA(hdc, x, y, lpstr, count, cTabStops, lpTabPos, nTabOrg);
}

extern WINAPI void wine32a_TabbedTextOutA(void);
__ASM_GLOBAL_FUNC(wine32a_TabbedTextOutA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TabbedTextOutA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $32, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_TabbedTextOutW(HDC hdc, INT x, INT y, LPCWSTR str, INT count, INT cTabStops, const INT * lpTabPos, INT nTabOrg)
{
	TRACE("Enter TabbedTextOutW\n");
	return pTabbedTextOutW(hdc, x, y, str, count, cTabStops, lpTabPos, nTabOrg);
}

extern WINAPI void wine32a_TabbedTextOutW(void);
__ASM_GLOBAL_FUNC(wine32a_TabbedTextOutW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TabbedTextOutW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $32, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_GetTabbedTextExtentA(HDC hdc, LPCSTR lpstr, INT count, INT cTabStops, const INT * lpTabPos)
{
	TRACE("Enter GetTabbedTextExtentA\n");
	return pGetTabbedTextExtentA(hdc, lpstr, count, cTabStops, lpTabPos);
}

extern WINAPI void wine32a_GetTabbedTextExtentA(void);
__ASM_GLOBAL_FUNC(wine32a_GetTabbedTextExtentA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetTabbedTextExtentA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_GetTabbedTextExtentW(HDC hdc, LPCWSTR lpstr, INT count, INT cTabStops, const INT * lpTabPos)
{
	TRACE("Enter GetTabbedTextExtentW\n");
	return pGetTabbedTextExtentW(hdc, lpstr, count, cTabStops, lpTabPos);
}

extern WINAPI void wine32a_GetTabbedTextExtentW(void);
__ASM_GLOBAL_FUNC(wine32a_GetTabbedTextExtentW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetTabbedTextExtentW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

static BOOL initialized = FALSE;

void wine_thunk_initialize_user32(void)
{
	HMODULE library = LoadLibraryA("user32.dll");
	pTrackPopupMenuEx = (void *)GetProcAddress(library, "TrackPopupMenuEx");
	pTrackPopupMenu = (void *)GetProcAddress(library, "TrackPopupMenu");
	pChangeMenuA = (void *)GetProcAddress(library, "ChangeMenuA");
	pChangeMenuW = (void *)GetProcAddress(library, "ChangeMenuW");
	pCheckMenuItem = (void *)GetProcAddress(library, "CheckMenuItem");
	pEnableMenuItem = (void *)GetProcAddress(library, "EnableMenuItem");
	pGetMenuStringA = (void *)GetProcAddress(library, "GetMenuStringA");
	pGetMenuStringW = (void *)GetProcAddress(library, "GetMenuStringW");
	pHiliteMenuItem = (void *)GetProcAddress(library, "HiliteMenuItem");
	pGetMenuState = (void *)GetProcAddress(library, "GetMenuState");
	pGetMenuItemCount = (void *)GetProcAddress(library, "GetMenuItemCount");
	pGetMenuItemID = (void *)GetProcAddress(library, "GetMenuItemID");
	pInsertMenuW = (void *)GetProcAddress(library, "InsertMenuW");
	pInsertMenuA = (void *)GetProcAddress(library, "InsertMenuA");
	pAppendMenuA = (void *)GetProcAddress(library, "AppendMenuA");
	pAppendMenuW = (void *)GetProcAddress(library, "AppendMenuW");
	pRemoveMenu = (void *)GetProcAddress(library, "RemoveMenu");
	pDeleteMenu = (void *)GetProcAddress(library, "DeleteMenu");
	pModifyMenuW = (void *)GetProcAddress(library, "ModifyMenuW");
	pModifyMenuA = (void *)GetProcAddress(library, "ModifyMenuA");
	pCreatePopupMenu = (void *)GetProcAddress(library, "CreatePopupMenu");
	pGetMenuCheckMarkDimensions = (void *)GetProcAddress(library, "GetMenuCheckMarkDimensions");
	pSetMenuItemBitmaps = (void *)GetProcAddress(library, "SetMenuItemBitmaps");
	pCreateMenu = (void *)GetProcAddress(library, "CreateMenu");
	pDestroyMenu = (void *)GetProcAddress(library, "DestroyMenu");
	pGetSystemMenu = (void *)GetProcAddress(library, "GetSystemMenu");
	pSetSystemMenu = (void *)GetProcAddress(library, "SetSystemMenu");
	pGetMenu = (void *)GetProcAddress(library, "GetMenu");
	pGetMenuBarInfo = (void *)GetProcAddress(library, "GetMenuBarInfo");
	pSetMenu = (void *)GetProcAddress(library, "SetMenu");
	pGetSubMenu = (void *)GetProcAddress(library, "GetSubMenu");
	pDrawMenuBar = (void *)GetProcAddress(library, "DrawMenuBar");
	pDrawMenuBarTemp = (void *)GetProcAddress(library, "DrawMenuBarTemp");
	pEndMenu = (void *)GetProcAddress(library, "EndMenu");
	pLoadMenuA = (void *)GetProcAddress(library, "LoadMenuA");
	pLoadMenuW = (void *)GetProcAddress(library, "LoadMenuW");
	pLoadMenuIndirectW = (void *)GetProcAddress(library, "LoadMenuIndirectW");
	pLoadMenuIndirectA = (void *)GetProcAddress(library, "LoadMenuIndirectA");
	pIsMenu = (void *)GetProcAddress(library, "IsMenu");
	pGetMenuItemInfoA = (void *)GetProcAddress(library, "GetMenuItemInfoA");
	pGetMenuItemInfoW = (void *)GetProcAddress(library, "GetMenuItemInfoW");
	pSetMenuItemInfoA = (void *)GetProcAddress(library, "SetMenuItemInfoA");
	pSetMenuItemInfoW = (void *)GetProcAddress(library, "SetMenuItemInfoW");
	pSetMenuDefaultItem = (void *)GetProcAddress(library, "SetMenuDefaultItem");
	pGetMenuDefaultItem = (void *)GetProcAddress(library, "GetMenuDefaultItem");
	pInsertMenuItemA = (void *)GetProcAddress(library, "InsertMenuItemA");
	pInsertMenuItemW = (void *)GetProcAddress(library, "InsertMenuItemW");
	pCheckMenuRadioItem = (void *)GetProcAddress(library, "CheckMenuRadioItem");
	pGetMenuItemRect = (void *)GetProcAddress(library, "GetMenuItemRect");
	pSetMenuInfo = (void *)GetProcAddress(library, "SetMenuInfo");
	pGetMenuInfo = (void *)GetProcAddress(library, "GetMenuInfo");
	pSetMenuContextHelpId = (void *)GetProcAddress(library, "SetMenuContextHelpId");
	pGetMenuContextHelpId = (void *)GetProcAddress(library, "GetMenuContextHelpId");
	pMenuItemFromPoint = (void *)GetProcAddress(library, "MenuItemFromPoint");
	pCalcMenuBar = (void *)GetProcAddress(library, "CalcMenuBar");
	pTranslateAcceleratorA = (void *)GetProcAddress(library, "TranslateAcceleratorA");
	pTranslateAcceleratorW = (void *)GetProcAddress(library, "TranslateAcceleratorW");
	pDrawTextExW = (void *)GetProcAddress(library, "DrawTextExW");
	pDrawTextExA = (void *)GetProcAddress(library, "DrawTextExA");
	pDrawTextW = (void *)GetProcAddress(library, "DrawTextW");
	pDrawTextA = (void *)GetProcAddress(library, "DrawTextA");
	pGrayStringA = (void *)GetProcAddress(library, "GrayStringA");
	pGrayStringW = (void *)GetProcAddress(library, "GrayStringW");
	pTabbedTextOutA = (void *)GetProcAddress(library, "TabbedTextOutA");
	pTabbedTextOutW = (void *)GetProcAddress(library, "TabbedTextOutW");
	pGetTabbedTextExtentA = (void *)GetProcAddress(library, "GetTabbedTextExtentA");
	pGetTabbedTextExtentW = (void *)GetProcAddress(library, "GetTabbedTextExtentW");
	initialized = TRUE;
}

void* wine_thunk_get_for_user32(void *func)
{
	if (!initialized)
		return NULL;

	if (func == pTrackPopupMenuEx)
		return wine32a_TrackPopupMenuEx;
	if (func == pTrackPopupMenu)
		return wine32a_TrackPopupMenu;
	if (func == pChangeMenuA)
		return wine32a_ChangeMenuA;
	if (func == pChangeMenuW)
		return wine32a_ChangeMenuW;
	if (func == pCheckMenuItem)
		return wine32a_CheckMenuItem;
	if (func == pEnableMenuItem)
		return wine32a_EnableMenuItem;
	if (func == pGetMenuStringA)
		return wine32a_GetMenuStringA;
	if (func == pGetMenuStringW)
		return wine32a_GetMenuStringW;
	if (func == pHiliteMenuItem)
		return wine32a_HiliteMenuItem;
	if (func == pGetMenuState)
		return wine32a_GetMenuState;
	if (func == pGetMenuItemCount)
		return wine32a_GetMenuItemCount;
	if (func == pGetMenuItemID)
		return wine32a_GetMenuItemID;
	if (func == pInsertMenuW)
		return wine32a_InsertMenuW;
	if (func == pInsertMenuA)
		return wine32a_InsertMenuA;
	if (func == pAppendMenuA)
		return wine32a_AppendMenuA;
	if (func == pAppendMenuW)
		return wine32a_AppendMenuW;
	if (func == pRemoveMenu)
		return wine32a_RemoveMenu;
	if (func == pDeleteMenu)
		return wine32a_DeleteMenu;
	if (func == pModifyMenuW)
		return wine32a_ModifyMenuW;
	if (func == pModifyMenuA)
		return wine32a_ModifyMenuA;
	if (func == pCreatePopupMenu)
		return wine32a_CreatePopupMenu;
	if (func == pGetMenuCheckMarkDimensions)
		return wine32a_GetMenuCheckMarkDimensions;
	if (func == pSetMenuItemBitmaps)
		return wine32a_SetMenuItemBitmaps;
	if (func == pCreateMenu)
		return wine32a_CreateMenu;
	if (func == pDestroyMenu)
		return wine32a_DestroyMenu;
	if (func == pGetSystemMenu)
		return wine32a_GetSystemMenu;
	if (func == pSetSystemMenu)
		return wine32a_SetSystemMenu;
	if (func == pGetMenu)
		return wine32a_GetMenu;
	if (func == pGetMenuBarInfo)
		return wine32a_GetMenuBarInfo;
	if (func == pSetMenu)
		return wine32a_SetMenu;
	if (func == pGetSubMenu)
		return wine32a_GetSubMenu;
	if (func == pDrawMenuBar)
		return wine32a_DrawMenuBar;
	if (func == pDrawMenuBarTemp)
		return wine32a_DrawMenuBarTemp;
	if (func == pEndMenu)
		return wine32a_EndMenu;
	if (func == pLoadMenuA)
		return wine32a_LoadMenuA;
	if (func == pLoadMenuW)
		return wine32a_LoadMenuW;
	if (func == pLoadMenuIndirectW)
		return wine32a_LoadMenuIndirectW;
	if (func == pLoadMenuIndirectA)
		return wine32a_LoadMenuIndirectA;
	if (func == pIsMenu)
		return wine32a_IsMenu;
	if (func == pGetMenuItemInfoA)
		return wine32a_GetMenuItemInfoA;
	if (func == pGetMenuItemInfoW)
		return wine32a_GetMenuItemInfoW;
	if (func == pSetMenuItemInfoA)
		return wine32a_SetMenuItemInfoA;
	if (func == pSetMenuItemInfoW)
		return wine32a_SetMenuItemInfoW;
	if (func == pSetMenuDefaultItem)
		return wine32a_SetMenuDefaultItem;
	if (func == pGetMenuDefaultItem)
		return wine32a_GetMenuDefaultItem;
	if (func == pInsertMenuItemA)
		return wine32a_InsertMenuItemA;
	if (func == pInsertMenuItemW)
		return wine32a_InsertMenuItemW;
	if (func == pCheckMenuRadioItem)
		return wine32a_CheckMenuRadioItem;
	if (func == pGetMenuItemRect)
		return wine32a_GetMenuItemRect;
	if (func == pSetMenuInfo)
		return wine32a_SetMenuInfo;
	if (func == pGetMenuInfo)
		return wine32a_GetMenuInfo;
	if (func == pSetMenuContextHelpId)
		return wine32a_SetMenuContextHelpId;
	if (func == pGetMenuContextHelpId)
		return wine32a_GetMenuContextHelpId;
	if (func == pMenuItemFromPoint)
		return wine32a_MenuItemFromPoint;
	if (func == pCalcMenuBar)
		return wine32a_CalcMenuBar;
	if (func == pTranslateAcceleratorA)
		return wine32a_TranslateAcceleratorA;
	if (func == pTranslateAcceleratorW)
		return wine32a_TranslateAcceleratorW;
	if (func == pDrawTextExW)
		return wine32a_DrawTextExW;
	if (func == pDrawTextExA)
		return wine32a_DrawTextExA;
	if (func == pDrawTextW)
		return wine32a_DrawTextW;
	if (func == pDrawTextA)
		return wine32a_DrawTextA;
	if (func == pGrayStringA)
		return wine32a_GrayStringA;
	if (func == pGrayStringW)
		return wine32a_GrayStringW;
	if (func == pTabbedTextOutA)
		return wine32a_TabbedTextOutA;
	if (func == pTabbedTextOutW)
		return wine32a_TabbedTextOutW;
	if (func == pGetTabbedTextExtentA)
		return wine32a_GetTabbedTextExtentA;
	if (func == pGetTabbedTextExtentW)
		return wine32a_GetTabbedTextExtentW;

	return NULL;
}
